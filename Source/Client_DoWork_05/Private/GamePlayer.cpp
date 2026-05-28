#include "Client_DoWork_05/Public/GamePlayer.h"



AGamePlayer::AGamePlayer()
{
	
	PrimaryActorTick.bCanEverTick = true;
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

