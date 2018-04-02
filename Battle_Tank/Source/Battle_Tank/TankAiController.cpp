// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "Engine/World.h"
#include "Battle_Tank.h"
#include "Tank.h"



void ATankAiController::BeginPlay()
{

	Super::BeginPlay();

	
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	
	if (PlayerTank)
	{
		// Aim Towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		//Fire when ready
		ControlledTank->Fire(); //TODO don't fire every frame
	}


}
