// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last import

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	 
	 public:
	 virtual void BeginPlay() override;
	 virtual void Tick(float DeltaTime) override;
	 
	 ATank *GetControlledTank() const;
	 void AimTowardsCrosshair()

	 
	
	
	
};
