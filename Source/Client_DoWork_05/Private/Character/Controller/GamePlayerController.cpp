#include "Character/Controller/GamePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "UI/Widget_PlayerHUD.h"

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
	
	if (Widget_PlayerHUDClass)
	{
		widget_PlayerHUDInst = CreateWidget<UWidget_PlayerHUD>(this, Widget_PlayerHUDClass);
		if (widget_PlayerHUDInst)
		{
			widget_PlayerHUDInst->AddToViewport();
		}
	}
}
