// Fill out your copyright notice in the Description page of Project Settings.


#include "Chest.h"

#include "Engine/Engine.h"


// Sets default values
AChest::AChest()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Chest"));
    VisualMesh->SetupAttachment(RootComponent);

    BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));

    BoxCollision->SetCollisionProfileName(TEXT("Trigger"));

    BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AChest::OnOverlapBegin);
    BoxCollision->OnComponentEndOverlap.AddDynamic(this, &AChest::OnOverlapEnd);



    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/AncientTreasures/Meshes/SM_Chest_02c.SM_Chest_02c"));

    if (CubeVisualAsset.Succeeded())
    {
        VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
        BoxCollision->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
        VisualMesh->SetWorldScale3D(FVector(0.5f));
    }

}

// Called when the game starts or when spawned
void AChest::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
// Called every frame
void AChest::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    FVector NewLocation = GetActorLocation();
    FRotator NewRotation = GetActorRotation();
    float RunningTime = GetGameTimeSinceCreation();
    float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
    NewLocation.Z += DeltaHeight * 20.0f;       //Scale our height by a factor of 20
    float DeltaRotation = DeltaTime * 20.0f;    //Rotate by 20 degrees per second
    NewRotation.Yaw += DeltaRotation;
    SetActorLocationAndRotation(NewLocation, NewRotation);
}

void AChest::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap Begin"));
}

void AChest::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap End"));
}