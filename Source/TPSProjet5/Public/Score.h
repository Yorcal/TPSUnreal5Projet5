// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Score.generated.h"

UCLASS()
class TPSPROJET5_API AScore : public AActor
{
	GENERATED_BODY()
		UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UUserWidget> WidgetClass;
	
public:	
	// Sets default values for this actor's properties
	AScore();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
