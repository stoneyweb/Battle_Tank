// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tank.h"
#include "TankAiController.h"


void ATankAiController::BeginPlay()
{

    Super::BeginPlay();

    auto ControlledTank=GetControlledTank();

    if(!ControlledTank)
    {
        UE_LOG(LogTemp,Warning,TEXT("AiController not possesing a Tank."))    
    }
    else
    {
        UE_LOG(LogTemp,Warning,TEXT("AiConttroller Possesing: %s."),*(ControlledTank->GetName()))
    }
  }

ATank *ATankAiController::GetControlledTank() const
{

    return Cast<ATank>(GetPawn());
    
    
}

