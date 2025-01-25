// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Userver : ModuleRules
{
	public Userver(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Sockets", "NetWorking" });
	}
}
