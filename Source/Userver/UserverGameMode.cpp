// Copyright Epic Games, Inc. All Rights Reserved.

#include "UserverGameMode.h"
#include "UserverCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUserverGameMode::AUserverGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
