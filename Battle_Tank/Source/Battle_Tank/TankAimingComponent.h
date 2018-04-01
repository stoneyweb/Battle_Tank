// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel; //forward declaration
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_TANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UTankBarrel *Barrel = nullptr;
	void MoveBarrelTowards(FVector AimDirection);

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void SetBarrellReference(UTankBarrel *BarrelToSet);

	//TODO set turret reference

	void AimAt(FVector HitLocation, float LaunchSpeed);

	
	
	

		
	
};
