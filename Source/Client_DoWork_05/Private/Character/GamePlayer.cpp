#include "Client_DoWork_05/Public/Character/GamePlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"


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
}


void AGamePlayer::BeginPlay()
{
	Super::BeginPlay();
	
	if (AGamePlayerController* PC = Cast<AGamePlayerController>(GetController()))
	{
		// UE_LOG(LogTemp,Warning,TEXT("Controller Was Caching"));
		OwnerController = PC;
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