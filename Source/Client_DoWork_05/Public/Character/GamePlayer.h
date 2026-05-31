#pragma once

#include "CoreMinimal.h"
#include "Controller/GamePlayerController.h"
#include "GameFramework/Character.h"
#include "GamePlayer.generated.h"

class UCameraComponent;
class USpringArmComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHPChanged, float,MaxHP,float,CurrentHP);

UCLASS()
class CLIENT_DOWORK_05_API AGamePlayer : public ACharacter
{
	GENERATED_BODY()

public:
	AGamePlayer();
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;
	
#pragma region DelegateFunctor
	UPROPERTY()
	FOnHPChanged OnHPChanged;
#pragma endregion 
	
protected:
#pragma region CameraSettings
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Camera")
	TObjectPtr<USpringArmComponent> SpringArmComp;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Camera")
	TObjectPtr<UCameraComponent> CameraComp;
#pragma endregion
	
#pragma region Controller
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="PlayerController")
	TObjectPtr<AGamePlayerController> OwnerController;
#pragma endregion 
	
#pragma region BindActionFunc
	void Player_Move();
#pragma endregion 
	
#pragma region Damamge
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
#pragma endregion 
	
#pragma region CharacterStat
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Stat")
	float MaxHP;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Stat")
	float CurrentHP;
#pragma endregion 
	
};
