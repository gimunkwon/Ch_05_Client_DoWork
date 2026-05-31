#pragma once

#include "CoreMinimal.h"
#include "Controller/GamePlayerController.h"
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
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;
	
protected:
#pragma region CameraSettings
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Camera")
	TObjectPtr<USpringArmComponent> SpringArmComp;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Camera")
	TObjectPtr<UCameraComponent> CameraComp;
#pragma endregion
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="PlayerController")
	TObjectPtr<AGamePlayerController> OwnerController;
	
#pragma region BindActionFunc
	void Player_Move();
#pragma endregion 
	
#pragma region CharacterStat
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Stat")
	float MaxHP;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Stat")
	float CurrentHP;
#pragma endregion 
	
};
