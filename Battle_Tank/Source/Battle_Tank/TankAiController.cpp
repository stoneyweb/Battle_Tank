// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "Engine/World.h"
#include "Battle_Tank.h"



void ATankAiController::BeginPlay()
{

	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AiController can't find Player Tank."))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AiConttroller found Player Tank: %s."), *(PlayerTank->GetName()))
	}


}

void ATankAiController::Tick(float DeltaTime)
{
	FVector HitLocation = GetPlayerTank()->GetActorLocation();
	FString AiTank = GetName();

	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		// Aim Towards the player
		GetControlledTank()->AimAt(HitLocation);
		//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *AiTank, *HitLocation.ToString())
	}

}

ATank *ATankAiController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());


}

ATank *ATankAiController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);

}