#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GamePlayerAnimInst.generated.h"

class AGamePlayer;

UCLASS()
class CLIENT_DOWORK_05_API UGamePlayerAnimInst : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="Stat")
	float GroundSpeed;
	
private:
	UPROPERTY()
	TObjectPtr<AGamePlayer> MyOwner;
};
