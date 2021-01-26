// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());;
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::BeginPlay()
{
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank"));
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("AIController is possesing %s"), (*ControlledTank->GetName()));

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("NO Player Tank Found"))
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Player Tank Found : %s"), (*PlayerTank->GetName()))
}
