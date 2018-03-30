// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{

    Super::BeginPlay();

    auto ControlledTank=GetControlledTank();

    if(!ControlledTank)
    {
        UE_LOG(LogTemp,Warning,TEXT("PlayerController not possesing a Tank."))    
    }
    else
    {
        UE_LOG(LogTemp,Warning,TEXT("PlayerController Possesing: %s."),*(ControlledTank->GetName()))
    }
    UE_LOG(LogTemp,Warning,TEXT("PlayerController Begin Play."))
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
        // UE_LOG(LogTemp,Warning,TEXT("Look Direction: %s"),*HitLocation.ToString())
         //TODO tell controlled tank to aim at this point
    }
   
    
}
//get world location of line trace through corsshair
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
   //find the crosshair position
   int32 ViewportSizeX, ViewportSizeY;
   GetViewportSize(ViewportSizeX,ViewportSizeY);
   auto ScreenLocation =FVector2D(ViewportSizeX*CrossHairXLocation,ViewportSizeY*CrossHairYLocation);
     
    return true;

}