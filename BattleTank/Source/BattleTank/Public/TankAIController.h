// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
private:
	// How close can AI Tank get
	float AcceptanceRadius{ 3000.0f }; // TODO check Radius Unit
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
