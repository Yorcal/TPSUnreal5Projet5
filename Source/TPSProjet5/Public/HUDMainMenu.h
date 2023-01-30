// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUDMainMenu.generated.h"

/**
 * 
 */
UCLASS()
class TPSPROJET5_API AHUDMainMenu : public AHUD
{
	GENERATED_BODY()
	
public:
	AHUDMainMenu();
	virtual void DrawHUD() override;
	virtual void BeginPlay() override;

};
