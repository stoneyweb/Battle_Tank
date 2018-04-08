// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.generated.h"


// Enum for Aiming State

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};


//forward declaration
class UTankBarrel; 
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_TANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Aiming;

private:
	UTankBarrel *Barrel = nullptr;
	UTankTurret *Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

		
	
public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void SetBarrellReference(UTankBarrel *BarrelToSet);
	void SetTurretReference(UTankTurret *TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

	
	
	

		
	
};
