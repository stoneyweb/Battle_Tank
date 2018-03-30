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
	 
	 private:
	 virtual void BeginPlay() override;
	 virtual void Tick(float DeltaTime) override;
	 
	 UPROPERTY(EditAnywhere)
	 float CrossHairXLocation =0.5;

	 UPROPERTY(EditAnywhere)
	 float CrossHairYLocation =0.33333;
	 
	ATank *GetControlledTank() const;
	 void AimTowardsCrosshair();

	 //Return an OUT parameter, true if hit landscape
	 bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	 
	
	
	
};
