// Fill out your copyright notice in the Description page of Project Settings.

#include "BulletController.h"
#include "EnemyController.h"
#include "SpaceShooterGameMode.h"
#include "Components/BoxComponent.h"


// Sets default values
ABulletController::ABulletController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create collider
	rootBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));

	// Listen for overlaps (i.e. collisions)
	rootBox->SetGenerateOverlapEvents(true);

	// If overlap, call this function
	rootBox->OnComponentBeginOverlap.AddDynamic(this, &ABulletController::OnOverlap);

	RootComponent = rootBox;
}

// Called when the game starts or when spawned
void ABulletController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABulletController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Get current location
	FVector newLocation = GetActorLocation();
	
	// Adjust the position
	newLocation.X += speed * DeltaTime;

	// Set new location
	SetActorLocation(newLocation);

	if (newLocation.X > 2000.0f)
	{
		this->Destroy();
	}
}

void ABulletController::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// If the bullet collides with an enemy
	if (OtherActor->IsA(AEnemyController::StaticClass()))
	{
		// Destroy the enemy
		OtherActor->Destroy();

		// Increment the score
		((ASpaceShooterGameMode*)GetWorld()->GetAuthGameMode())->IncrementScore();

		// Destroy the bullet
		this->Destroy();
	}
}