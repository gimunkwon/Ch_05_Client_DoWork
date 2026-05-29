#include "Character/Controller/GamePlayerController.h"
#include "EnhancedInputSubsystems.h"

AGamePlayerController::AGamePlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void AGamePlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* EnhancedSubSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			UE_LOG(LogTemp,Warning,TEXT("IMC Mapping Completed"));
			EnhancedSubSystem->AddMappingContext(IMC_Default,0);
		}
	}
}
