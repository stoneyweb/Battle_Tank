// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "Engine/World.h"
#include "Battle_Tank.h"
#include "TankAimingComponent.h"



void ATankAiController::BeginPlay()
{

	Super::BeginPlay();

	
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	
	
	
	
	if (!ensure(PlayerTank && ControlledTank)) { return; }
	
	// Move Towards the Player
	MoveToActor(PlayerTank,AcceptanceRadius); // TODO Check if Distance is in cm
		
	// Aim Towards the player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	
	//Fire when ready
	AimingComponent->Fire(); //TODO don't fire every frame



}
