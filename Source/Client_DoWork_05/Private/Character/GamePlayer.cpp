#include "Client_DoWork_05/Public/Character/GamePlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


AGamePlayer::AGamePlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	
#pragma region CameraSetting
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 600.f;
	SpringArmComp->SetRelativeRotation(FRotator(-60.f,0.f,0.f));
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComp->SetupAttachment(SpringArmComp);
#pragma endregion
}


void AGamePlayer::BeginPlay()
{
	Super::BeginPlay();
}


void AGamePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AGamePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

