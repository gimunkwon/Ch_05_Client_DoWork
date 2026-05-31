#include "Client_DoWork_05/Public/Character/GamePlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "UI/Widget_PlayerHUD.h"


AGamePlayer::AGamePlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	
#pragma region CameraSetting
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 600.f;
	SpringArmComp->SetRelativeRotation(FRotator(-60.f,0.f,0.f));
	SpringArmComp->bUsePawnControlRotation = false;
	SpringArmComp->bInheritPitch = false;
	SpringArmComp->bInheritRoll = false;
	SpringArmComp->bInheritYaw = false;
	SpringArmComp->bDoCollisionTest = false;
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComp->SetupAttachment(SpringArmComp);
	CameraComp->bUsePawnControlRotation = false;
#pragma endregion
	
#pragma region CharacterMovement
	GetCharacterMovement()->bOrientRotationToMovement = true;
#pragma endregion
	
#pragma region StatSettings
	MaxHP = 100.f;
	CurrentHP = MaxHP;
#pragma endregion 
	
}


void AGamePlayer::BeginPlay()
{
	Super::BeginPlay();
	
	if (AGamePlayerController* PC = Cast<AGamePlayerController>(GetController()))
	{
		// UE_LOG(LogTemp,Warning,TEXT("Controller Was Caching"));
		OwnerController = PC;
	}
	if (OwnerController)
	{
		OwnerController->InitializeHUD(MaxHP,CurrentHP);
		if (OwnerController->widget_PlayerHUDInst)
		{
			OnHPChanged.AddDynamic(OwnerController->widget_PlayerHUDInst, &UWidget_PlayerHUD::SetHPProgressBar);
		}
	}
}


void AGamePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AGamePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (AGamePlayerController* PC = Cast<AGamePlayerController>(GetController()))
	{
		if (UEnhancedInputComponent* EInputComp = Cast<UEnhancedInputComponent>(InputComponent))
		{
			// UE_LOG(LogTemp,Warning,TEXT("PlayerMove Binding"));
			EInputComp->BindAction(PC->IA_Move, ETriggerEvent::Triggered, this, &AGamePlayer::Player_Move);
		}
	}
}

void AGamePlayer::Player_Move()
{
	// UE_LOG(LogTemp,Warning,TEXT("Player MoveStart"));
	if (!OwnerController) return;

	FHitResult HitResult;
	if (OwnerController->GetHitResultUnderCursor(ECC_Visibility, false, HitResult))
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(OwnerController, HitResult.Location);
	}
}

float AGamePlayer::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator, AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	CurrentHP = FMath::Clamp(CurrentHP - ActualDamage, 0.f, MaxHP);

	if (OnHPChanged.IsBound())
	{
		OnHPChanged.Broadcast(MaxHP,CurrentHP);
	}
	
	return ActualDamage;
}
