// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
		// todo clamp actual throttle so player cant override
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}



