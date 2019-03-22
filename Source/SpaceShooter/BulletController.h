// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpaceShooterGameMode.h"
#include "GameFramework/Actor.h"
#include "BulletController.generated.h"

UCLASS()
class SPACESHOOTER_API ABulletController : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABulletController();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		UShapeComponent* rootBox;

	UPROPERTY(EditAnywhere)
		float speed = 600.0f;

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
