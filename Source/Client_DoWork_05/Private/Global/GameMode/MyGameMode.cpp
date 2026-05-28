#include "Client_DoWork_05/Public/Global/GameMode/MyGameMode.h"

AMyGameMode::AMyGameMode()
{
	if (GamePawnClass)
	{
		DefaultPawnClass = GamePawnClass;
	}
	if (GamePlayerControllerClass)
	{
		PlayerControllerClass = GamePlayerControllerClass;
	}
}
