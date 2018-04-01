// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"

//forward declaration
class ATank;
UCLASS()
class BATTLE_TANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


	ATank *GetControlledTank() const;
	ATank *GetPlayerTank() const;



};
