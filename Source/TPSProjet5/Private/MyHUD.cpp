// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"


AMyHUD::AMyHUD()
{

	static ConstructorHelpers::FClassFinder<UUserWidget> ScoreTextObj(TEXT("/Game/WG_SCORE.WG_SCORE_C"));
	ScoreWidgetClass = ScoreTextObj.Class;
}

void AMyHUD::DrawHUD()
{
	Super::DrawHUD();
	
}

void AMyHUD::BeginPlay()
{
	Super::BeginPlay();


	if (ScoreWidgetClass != nullptr)
	{
		CurrentScoreWidget = CreateWidget<UUserWidget>(GetWorld(), ScoreWidgetClass);
		if (CurrentScoreWidget) {
			CurrentScoreWidget->AddToViewport();
		}
	}
}