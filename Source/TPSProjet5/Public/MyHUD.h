// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class TPSPROJET5_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AMyHUD();
	virtual void DrawHUD() override;
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditAnywhere)
		UTexture2D* CrosshairTexture;

	UPROPERTY(EditAnywhere, category = "Score")
		TSubclassOf<class UUserWidget> ScoreWidgetClass;
	
	UPROPERTY(EditAnywhere, category = "Score")
		class UUserWidget* CurrentScoreWidget;
};
