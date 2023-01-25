// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"


AMyHUD::AMyHUD()
{
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/Textures/FirstPersonCrosshair"));
	//CrosshairTexture = CrosshairTexObj.Object;

	static ConstructorHelpers::FClassFinder<UUserWidget> ScoreTextObj(TEXT("/Game/WG_SCORE"));
	ScoreWidgetClass = ScoreTextObj.Class;
}

void AMyHUD::DrawHUD()
{
	Super::DrawHUD();

	/*if (CrosshairTexture)
	{
		FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
		FVector2D CrosshairDrawPosition(Center.X - (CrosshairTexture->GetSurfaceWidth() * 0.5f), Center.Y - (CrosshairTexture->GetSurfaceHeight() * 0.5f));
		FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTexture->Resource, FLinearColor::White);
		TileItem.BlendMode = SE_BLEND_Translucent;
		Canvas->DrawItem(TileItem);
	}*/
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