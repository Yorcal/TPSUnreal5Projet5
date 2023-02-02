// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "MoveBoat.generated.h"

UCLASS()
class TPSPROJET5_API AMoveBoat : public AActor
{
	GENERATED_BODY()
		UPROPERTY(VisibleAnywhere) UStaticMeshComponent* VisualMesh;
	
public:	
	// Sets default values for this actor's properties
	AMoveBoat();
	UPROPERTY(EditAnywhere, Category = "MoveBoat")
	bool CanMove = false;

	UPROPERTY(EditAnywhere, Category = "Collision") UBoxComponent* BoxCollision;
	UPROPERTY(EditAnywhere, Category = "Collision1") UBoxComponent* BoxCollision1;
	UPROPERTY(EditAnywhere, Category = "Collision2") UBoxComponent* BoxCollision2;
	UPROPERTY(EditAnywhere, Category = "Collision3") UBoxComponent* BoxCollision3;
	UPROPERTY(EditAnywhere, Category = "Collision3") UBoxComponent* BoxCollision4;
	UPROPERTY(EditAnywhere, Category = "Collision3") UBoxComponent* BoxCollisionBoat;
	UPROPERTY(EditAnywhere, Category = "Collision3") UBoxComponent* BoxCollisionEnd;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
