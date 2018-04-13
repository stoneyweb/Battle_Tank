// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Engine/World.h"


UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
	
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);

}

void UTankTrack::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	DriveTrack();
	ApplySidewaysForce();
	CurrentThrottle = 0;
	
}


void UTankTrack::ApplySidewaysForce()
{
	auto DeltaTime = GetWorld()->GetDeltaSeconds();

	// calculate the slippige speed
	auto SlippageSpeed = FVector::CrossProduct(GetRightVector(),GetComponentVelocity());

	// work-out the required accelaration this frame to correct
	auto CorrectionAccelaration = -SlippageSpeed / DeltaTime * GetRightVector();

	//calculate and apply sideways force (F = m a)
	auto TankRoot = Cast <UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = TankRoot->GetMass() * CorrectionAccelaration / 2;

	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float Throttle)
{
	CurrentThrottle = CurrentThrottle + Throttle;
	FMath::Clamp(CurrentThrottle, -1.f, 1.f);

	

}
void UTankTrack::DriveTrack()
{
	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

	
}


