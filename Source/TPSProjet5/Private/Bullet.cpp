// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bullet"));
    VisualMesh->SetupAttachment(RootComponent);



    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/AncientTreasures/Meshes/SM_Coin_02a.SM_Coin_02a"));
    if (CubeVisualAsset.Succeeded())
    {
        VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeScale3D(FVector(3.f, 3.f, 3.f));
    }
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    FVector NewLocation = GetActorLocation();
    FRotator NewRotation = GetActorRotation();
    float RunningTime = GetGameTimeSinceCreation();
    float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
    float DeltaRotation = DeltaTime * 100.f;    //Rotate by 20 degrees per second
    NewRotation.Pitch += DeltaRotation;
    NewRotation.Yaw += DeltaRotation;
    SetActorLocationAndRotation(NewLocation, NewRotation);
	VisualMesh->AddRelativeLocation(FVector(5.f, 0.f, 0.f));
    
    //Destroy after xTime
	if (RunningTime > 5.f)
	{
		Destroy();
	}

}

