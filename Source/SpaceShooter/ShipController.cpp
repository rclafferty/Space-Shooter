// Fill out your copyright notice in the Description page of Project Settings.

#include "ShipController.h"
#include "BulletController.h"
#include "EnemyController.h"
#include "Engine/World.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AShipController::AShipController()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Make a UBoxComponent for collisions
	collisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));

	// Listen for overlaps (i.e. collisions)
	collisionBox->SetGenerateOverlapEvents(true);

	// If overlap, call this function
	collisionBox->OnComponentBeginOverlap.AddDynamic(this, &AShipController::OnOverlap);

	// Automatically receive player 0 input
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AShipController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShipController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!currentVelocity.IsZero())
	{
		// Compute new location
		FVector distanceTraveled = speed * currentVelocity * DeltaTime;
		FVector newLocation = GetActorLocation() + distanceTraveled;

		// Set new location
		SetActorLocation(newLocation);
	}
}

// Called to bind functionality to input
void AShipController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Make the player move up/down
	InputComponent->BindAxis("Move_X", this, &AShipController::Move_XAxis);

	// Make the player move left/right
	InputComponent->BindAxis("Move_Y", this, &AShipController::Move_YAxis);

	// Make the player shoot
	InputComponent->BindAction("Shoot", IE_Pressed, this, &AShipController::OnShoot);
}

void AShipController::Move_XAxis(float axisValue)
{
	currentVelocity.X = axisValue * MOVEMENT_MODIFIER;
}

void AShipController::Move_YAxis(float axisValue)
{
	currentVelocity.Y = axisValue * MOVEMENT_MODIFIER;
}

void AShipController::OnShoot()
{
	UWorld* world = GetWorld();

	// If world exists
	if (world)
	{
		// Get current location
		FVector location = GetActorLocation();

		FVector offset = FVector(20.0f, 0.0f, 0.0f);

		// Spawn the bullet
		world->SpawnActor<ABulletController>(BulletBlueprint, location + offset, FRotator::ZeroRotator); // Need #include "Engine/World.h" to compile
	}
}

void AShipController::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// If the ship collides with an enemy
	if (OtherActor->IsA(AEnemyController::StaticClass()))
	{
		// Set the died flag to true
		died = true;

		// Hide the ship
		this->SetActorHiddenInGame(true);

		// Pause the game
		UGameplayStatics::SetGamePaused(GetWorld(), true);
	}
}