// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
protected:
	// How close can AI Tank get
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius{ 8000.0f }; // TODO check Radius Unit
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
