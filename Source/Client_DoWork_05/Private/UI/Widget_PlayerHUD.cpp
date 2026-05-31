#include "UI/Widget_PlayerHUD.h"

#include "Components/ProgressBar.h"


void UWidget_PlayerHUD::SetHPProgressBar(float MaxHP, float CurrentHP)
{
	if (PB_PlayerHP)
	{
		PB_PlayerHP->SetPercent(MaxHP / CurrentHP);
	}
}
