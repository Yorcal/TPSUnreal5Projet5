// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TPSProjet5Character.h"
#include "TPSProjet5GameMode.generated.h"


UENUM()
enum class EGameModeState
{
	Playing,
	Paused
};

UCLASS(minimalapi)
class ATPSProjet5GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATPSProjet5GameMode();
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	ATPSProjet5Character* MyCharacter;
	
	void GetCurrentState(EGameModeState NewState);

	void SetCurrentState(EGameModeState NewState);
	
private:
	EGameModeState CurrentState;

	void HandleNewState(EGameModeState NewState);
};



