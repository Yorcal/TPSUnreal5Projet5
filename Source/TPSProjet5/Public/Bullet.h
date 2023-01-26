// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class TPSPROJET5_API ABullet : public AActor
{
	GENERATED_BODY()
		UPROPERTY(VisibleAnywhere) UStaticMeshComponent* VisualMesh;
	
public:	
	// Sets default values for this actor's properties
	ABullet();

	FVector DirectionBullet;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	FVector GetDirection();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
