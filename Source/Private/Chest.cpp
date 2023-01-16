// Fill out your copyright notice in the Description page of Project Settings.


#include "Chest.h"

// Sets default values
AChest::AChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}
//Called if the player is close enough to the chest
void AChest::OpenChest()
{
	//If the chest is not already open
	if (!bIsOpen)
	{
		//Open the chest
		bIsOpen = true;
		//print a message to the screen
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Chest Opened"));
		//Play the opening animation
		//Play the opening sound
		//Spawn the items
	}
}
