// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveBoat.h"
#include "TPSProjet5/TPSProjet5Character.h"

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

    BoxCollision1 = CreateDefaultSubobject<UBoxComponent>(TEXT("Stop Arret"));
    BoxCollision1->SetCollisionProfileName(TEXT("Trigger1"));
    BoxCollision1->OnComponentBeginOverlap.AddDynamic(this, &AMoveBoat::OnOverlapBegin);
    BoxCollision1->OnComponentEndOverlap.AddDynamic(this, &AMoveBoat::OnOverlapEnd);

    BoxCollision2 = CreateDefaultSubobject<UBoxComponent>(TEXT("Redemarrage"));
    BoxCollision2->SetCollisionProfileName(TEXT("Trigger2"));
    BoxCollision2->OnComponentBeginOverlap.AddDynamic(this, &AMoveBoat::OnOverlapBegin);
    BoxCollision2->OnComponentEndOverlap.AddDynamic(this, &AMoveBoat::OnOverlapEnd);

    BoxCollision3 = CreateDefaultSubobject<UBoxComponent>(TEXT("Stop deuxieme Arret"));
    BoxCollision3->SetCollisionProfileName(TEXT("Trigger3"));
    BoxCollision3->OnComponentBeginOverlap.AddDynamic(this, &AMoveBoat::OnOverlapBegin);
    BoxCollision3->OnComponentEndOverlap.AddDynamic(this, &AMoveBoat::OnOverlapEnd);

    BoxCollisionBoat = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Du Bateau"));
	BoxCollisionBoat->SetupAttachment(VisualMesh);


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
        VisualMesh->AddRelativeLocation(FVector(0.f, 3.f, 0.f));
		BoxCollisionBoat->AddRelativeLocation(FVector(0.f, 3.f, 0.f));
    }
        
}
void AMoveBoat::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap Begin"));
    APlayerController* PlayerController = GEngine->GetFirstLocalPlayerController(GetWorld());
    ATPSProjet5Character* Player = Cast<ATPSProjet5Character>(PlayerController->GetPawn());
	if (OverlappedComp == BoxCollision && OtherActor == Player)
    {
        CanMove = true;
        //remove the box collision
        BoxCollision->DestroyComponent();
    }
	else if (OverlappedComp == BoxCollision1 && OtherActor == Player)
    {
        CanMove = false;
        BoxCollision1->DestroyComponent();
    }
    else if (OverlappedComp == BoxCollision2 && OtherActor == Player)
    {
        CanMove = true;
        BoxCollision2->DestroyComponent();
    }
    else if (OverlappedComp == BoxCollision3 /* && OtherActor == BoxCollisionBoat*/)
    {
        CanMove = false;
        BoxCollision3->DestroyComponent();
    }
}

void AMoveBoat::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    
}


