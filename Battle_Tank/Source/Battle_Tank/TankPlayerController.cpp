// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Battle_Tank.h"




void ATankPlayerController::BeginPlay()
{

	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a Tank."))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possesing: %s."), *(ControlledTank->GetName()))
	}
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play."))
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

}

ATank *ATankPlayerController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());

}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // out parameter
	if (GetSightRayHitLocation(HitLocation)) // has side-effect going to line trace
	{
		//TODO tell controlled tank to aim at this point
		GetControlledTank()->AimAt(HitLocation);
	}


}
//get world location of line trace through corsshair
bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const
{
	//find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	FVector LookDirection;
	
	//"De-Project" the screen position of the crosshair to a world direction
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// Line-trace along that look direction, and see what we hit (up to max range)
		GetLookVectorHitLocation(LookDirection,HitLocation);		
	}
	
	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection*LineTraceRange);
	
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult, 
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation=HitResult.Location;
		return true;
	}
	
	HitLocation = FVector(0);
	UE_LOG(LogTemp, Error, TEXT("No Target in sight,Sir!"))
	
	return false;
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const
{
	FVector CameraWorldLocation; // for disgarding
	
	DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		LookDirection
	);
	
	return true;
}
