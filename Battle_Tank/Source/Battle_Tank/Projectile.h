// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/Pawn.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLE_TANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void LaunchProjectile(float Speed);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UProjectileMovementComponent *ProjectileMovement=nullptr;
	
	UPROPERTY(VisibleAnywhere, Category="Component")
		UStaticMeshComponent *CollisionMesh=nullptr;

	UPROPERTY(VisibleAnywhere, Category="Component")
		UParticleSystemComponent *LaunchBlast = nullptr;
			
	
};
