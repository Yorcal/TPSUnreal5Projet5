// Copyright Epic Games, Inc. All Rights Reserved.

#include "TPSProjet5GameMode.h"
#include "TPSProjet5Character.h"
#include "Kismet/GameplayStatics.h"
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

void ATPSProjet5GameMode::BeginPlay()
{
	Super::BeginPlay();

	// Set the current state to playing
	CurrentState = EGameModeState::Playing;
	
	MyCharacter = Cast<ATPSProjet5Character>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void ATPSProjet5GameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ATPSProjet5GameMode::GetCurrentState(EGameModeState NewState)
{
	CurrentState = NewState;
}

void ATPSProjet5GameMode::SetCurrentState(EGameModeState NewState)
{
	// Set the current state
	CurrentState = NewState;
	// Handle any state change functionality
	HandleNewState(CurrentState);
}

void ATPSProjet5GameMode::HandleNewState(EGameModeState NewState)
{
	// Handle the new current state
	switch (NewState)
	{
	case EGameModeState::Playing:
		// Resume gameplay
		break;
	case EGameModeState::Paused:
		// Pause gameplay
		break;
	default:
		// Unknown/default state
		break;
	}
}