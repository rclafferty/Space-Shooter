// Fill out your copyright notice in the Description page of Project Settings.

// IMPORTANT: Instructor source file

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ShipController.generated.h"

UCLASS()
class SPACESHOOTER_API AShipController : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShipController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
		UShapeComponent* collisionBox;

	UPROPERTY(EditAnywhere)
		float speed = 10.0f;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class ABulletController> BulletBlueprint;

	void Move_XAxis(float axisValue);
	void Move_YAxis(float axisValue);

	void OnShoot();
	void OnRestart();
	
	FVector currentVelocity;

	const float MOVEMENT_MODIFIER = 100.0f;

	bool died;

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
