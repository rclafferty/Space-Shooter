// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyController.h"
#include "Components/BoxComponent.h"


// Sets default values
AEnemyController::AEnemyController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Make the collider
	rootBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));

	// Listen for overlaps (i.e. collisions)
	rootBox->SetGenerateOverlapEvents(true);

	RootComponent = rootBox;
}

// Called when the game starts or when spawned
void AEnemyController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Get current location
	FVector newLocation = GetActorLocation();
	
	// Adjust new location
	newLocation.X += speed * DeltaTime;
	
	// Set new location
	SetActorLocation(newLocation);

	if (newLocation.X < -600.0f)
	{
		this->Destroy();
	}
}

