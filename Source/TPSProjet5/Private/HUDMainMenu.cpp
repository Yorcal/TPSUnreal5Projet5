// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDMainMenu.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"


AHUDMainMenu::AHUDMainMenu()
{

	static ConstructorHelpers::FClassFinder<UUserWidget> ScoreTextObj(TEXT("/Game/WG_MainMenu.WG_MainMenu_C"));
}

void AHUDMainMenu::DrawHUD()
{
	Super::DrawHUD();

}

void AHUDMainMenu::BeginPlay()
{
	Super::BeginPlay();
}