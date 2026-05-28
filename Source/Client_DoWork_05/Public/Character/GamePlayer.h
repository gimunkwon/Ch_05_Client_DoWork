#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GamePlayer.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class CLIENT_DOWORK_05_API AGamePlayer : public ACharacter
{
	GENERATED_BODY()

public:
	AGamePlayer();
protected:
	virtual void BeginPlay() override;
	
#pragma region CameraSettings
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Camera")
	TObjectPtr<USpringArmComponent> SpringArmComp;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Camera")
	TObjectPtr<UCameraComponent> CameraComp;
#pragma endregion 
	
public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
