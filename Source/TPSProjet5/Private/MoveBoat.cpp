// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveBoat.h"

// Sets default values
AMoveBoat::AMoveBoat()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bullet"));
    VisualMesh->SetupAttachment(RootComponent);

    BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));

    BoxCollision->SetCollisionProfileName(TEXT("Trigger"));

    BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AMoveBoat::OnOverlapBegin);
    BoxCollision->OnComponentEndOverlap.AddDynamic(this, &AMoveBoat::OnOverlapEnd);



    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/EF_Lewis/Meshes/boatSmall_a.boatSmall_a"));
    if (CubeVisualAsset.Succeeded())
    {
        VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
        VisualMesh->SetRelativeScale3D(FVector(4.f, 4.f, 4.f));
    }
}

// Called when the game starts or when spawned
void AMoveBoat::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoveBoat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if (CanMove == true) {
        FVector NewLocation = GetActorLocation();
        float RunningTime = GetGameTimeSinceCreation();
        float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
        SetActorLocation(NewLocation);
        VisualMesh->AddRelativeLocation(FVector(0.f, 1.f, 0.f));
    }
        
}
void AMoveBoat::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap Begin"));
}

void AMoveBoat::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}


