// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameWidget.h"
#include "GameFramework/GameMode.h"
#include "SpaceShooterGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API ASpaceShooterGameMode : public AGameMode
{
	GENERATED_BODY()


protected:
	int score = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
		TSubclassOf<UUserWidget> StartingWidgetClass;

	UPROPERTY()
		UUserWidget* CurrentWidget;

public:
	void IncrementScore();
	void OnGameOver();

	// Minimum interval between enemies spawning
	const float MINIMUM_INTERVAL = 0.5f;

	// Maximum interval between enemies spawning
	const float MAXIMUM_INTERVAL = 2.0f;

	// Time before speeding up the spawn rate
	const float TIME_TO_MINIMUM_INTERVAL = 30.0f;

	// Pointer to enemy blueprint
	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class AEnemyController> EnemyBlueprint;

	// Timer to spawn enemy
	float enemyTimer;

	// Keep track of how long the game has gone on
	float gameTimer;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "UMG Game")
		void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);
};
