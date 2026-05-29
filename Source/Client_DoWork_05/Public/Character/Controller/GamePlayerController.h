#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GamePlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class CLIENT_DOWORK_05_API AGamePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AGamePlayerController();
	
	virtual void BeginPlay() override;
	
#pragma region InputActions
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="InputAction")
	TObjectPtr<UInputMappingContext> IMC_Default;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="InputAction")
	TObjectPtr<UInputAction> IA_Move;
#pragma endregion 
	
};
