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
    if (!GetControlledTank){return;}
    //Get world Location where the Crosshair hits through linetrace
    //if crosshair hits landscape
    // tell the controller what it hits

}