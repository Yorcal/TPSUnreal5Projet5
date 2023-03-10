// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Chest.generated.h"


UCLASS()
class TPSPROJET5_API AChest : public AActor
{
    GENERATED_BODY()
        UPROPERTY(VisibleAnywhere) UStaticMeshComponent* VisualMesh;
        UPROPERTY(VisibleAnywhere) UStaticMeshComponent* ChestOpen;
        UPROPERTY(VisibleAnywhere) UParticleSystemComponent* FXChestClose;
        UPROPERTY(VisibleAnywhere) UParticleSystemComponent* FXChestOpen;
        



public:
    // Sets default values for this actor's properties
    AChest();
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, Category = "Collision") UBoxComponent* BoxCollision;

    UFUNCTION()
        void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
        void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    UFUNCTION()
        void GiveScore();
    
protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;      
};