// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"

//forward declaration
class UTankAimingComponent;

UCLASS()
class BATTLE_TANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()

private:
	//How close can the AiTank get
	float AcceptanceRadius = 3000;

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


};
