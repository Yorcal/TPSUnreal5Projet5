// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TPSProjet5 : ModuleRules
{
	public TPSProjet5(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "Slate", "SlateCore", "UMG" });
    }
}
