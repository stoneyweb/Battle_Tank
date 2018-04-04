// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//forward declaration
class UTankBarrel;
class UTankAimingComponent;
class UTankMovementComponent;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLE_TANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	
	// Sets default values for this pawn's properties
	ATank();
	
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category =Setup )
		void SetBarrelReference(UTankBarrel *BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret *TurretToSet);

	UFUNCTION(BlueprintCallable)
		void Fire();


protected:
	UTankAimingComponent *TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = Setup)
	UTankMovementComponent *TankMovementComponent = nullptr;

private:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInSeconds = 3;
	
		

	UTankBarrel *Barrel=nullptr; // local reference of spawning projectiles
	
	double LastFireTime = 0;


	
};
