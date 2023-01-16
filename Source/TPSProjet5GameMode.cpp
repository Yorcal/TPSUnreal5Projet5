// Copyright Epic Games, Inc. All Rights Reserved.

#include "TPSProjet5GameMode.h"
#include "TPSProjet5Character.h"
#include "UObject/ConstructorHelpers.h"

ATPSProjet5GameMode::ATPSProjet5GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
