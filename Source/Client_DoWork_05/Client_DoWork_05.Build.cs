// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Client_DoWork_05 : ModuleRules
{
	public Client_DoWork_05(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput" });
    }
}
