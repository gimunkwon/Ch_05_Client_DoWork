#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widget_PlayerHUD.generated.h"

class UProgressBar;

UCLASS()
class CLIENT_DOWORK_05_API UWidget_PlayerHUD : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UProgressBar> PB_PlayerHP;
	
};
