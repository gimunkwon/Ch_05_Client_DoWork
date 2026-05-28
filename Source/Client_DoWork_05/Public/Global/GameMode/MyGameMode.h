#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MyGameMode.generated.h"

UCLASS()
class CLIENT_DOWORK_05_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	AMyGameMode();
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="PawnClass")
	TSubclassOf<APawn> GamePawnClass;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="ControllerClass")
	TSubclassOf<APlayerController> GamePlayerControllerClass;
};
