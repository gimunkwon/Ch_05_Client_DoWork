#include "Character/Animations/GamePlayerAnimInst.h"

#include "Character/GamePlayer.h"

void UGamePlayerAnimInst::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	MyOwner = Cast<AGamePlayer>(TryGetPawnOwner());
}

void UGamePlayerAnimInst::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	if (!MyOwner)
	{
		return;
	}
	
	GroundSpeed = MyOwner->GetVelocity().Size2D();
}
