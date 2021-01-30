// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation{ 0.5f };
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation{ 0.33f };

	ATank* GetControlledTank() const;

	// Return out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	// Start moving the tank barrel so that a shot would hit where the crosshair intersect the world
	void AimTowardsCrosshair();

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};