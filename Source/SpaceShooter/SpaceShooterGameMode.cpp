// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceShooterGameMode.h"
#include "EnemyController.h"
#include "Engine/World.h"

void ASpaceShooterGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void ASpaceShooterGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Keep track of how long the game has gone on
	gameTimer += DeltaTime;

	// Count down to spawn next enemy
	enemyTimer -= DeltaTime;

	// If time to spawn the enemy
	if (enemyTimer <= 0.0f)
	{
		float difficultyPercentage = FMath::Min(gameTimer / TIME_TO_MINIMUM_INTERVAL, 1.0f);

		// Gradually speed up the enemy timer
		enemyTimer = MAXIMUM_INTERVAL - ((MAXIMUM_INTERVAL - MINIMUM_INTERVAL) * difficultyPercentage);

		// Spawn the enemy

		// Get pointer to current world
		UWorld* world = GetWorld();

		// If world exists
		if (world)
		{
			// Generate random location at the following specs:
			// X = 1800
			// Y = Between -1200 and 1200
			// Z = 0
			FVector location = FVector(1800.0f, FMath::RandRange(-1200.0f, 1200.0f), 0.0f);

			// Spawn the enemy
			world->SpawnActor<AEnemyController>(EnemyBlueprint, location, FRotator::ZeroRotator); // Need #include "Engine/World.h" to compile
		}
	}
}