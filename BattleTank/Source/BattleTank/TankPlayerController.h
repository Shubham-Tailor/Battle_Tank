// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
class UTankAimingComponent;

/*
* Responsible for Player Aiming
*/
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation{ 0.5f };

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation{ 0.33f };

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange {1000000.f};

	// Return out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	// Start moving the tank barrel so that a shot would hit where the crosshair intersect the world
	void AimTowardsCrosshair();

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
