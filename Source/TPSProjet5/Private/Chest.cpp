// Fill out your copyright notice in the Description page of Project Settings.


#include "Chest.h"
#include "TPSProjet5/TPSProjet5Character.h"
#include "Engine/Engine.h"


// Sets default values
AChest::AChest()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Chest"));
    VisualMesh->SetupAttachment(RootComponent);
	ChestOpen = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ChestOpen"));
	ChestOpen->SetupAttachment(RootComponent);
	FXChestClose = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FXChestClose"));
    FXChestOpen = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FXChestOpen"));
    
    

    BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));

    BoxCollision->SetCollisionProfileName(TEXT("Trigger"));

    BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AChest::OnOverlapBegin);
    BoxCollision->OnComponentEndOverlap.AddDynamic(this, &AChest::OnOverlapEnd);



    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/AncientTreasures/Meshes/SM_Chest_02c.SM_Chest_02c"));
    
    if (CubeVisualAsset.Succeeded())
    {
        VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
        BoxCollision->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    }
    //attack boxcolision to actor
	BoxCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AChest::BeginPlay()
{
    Super::BeginPlay();
    ChestOpen->SetVisibility(false);
	FXChestOpen->SetVisibility(false);
}

// Called every frame
// Called every frame
void AChest::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void AChest::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	VisualMesh->SetVisibility(false);
    VisualMesh->SetStaticMesh(ChestOpen->GetStaticMesh());
    VisualMesh->SetVisibility(true);

    //get Player
    APlayerController* PlayerController = GEngine->GetFirstLocalPlayerController(GetWorld());
	if (PlayerController)
	{
        ATPSProjet5Character* Player = Cast<ATPSProjet5Character>(PlayerController->GetPawn());
		if (Player)
		{
			Player->AddScore(100);
		}
	}
	FXChestClose->DestroyComponent();
	FXChestOpen->SetVisibility(true);
}

void AChest::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    BoxCollision->DestroyComponent();
}

void AChest::GiveScore()
{
    
}