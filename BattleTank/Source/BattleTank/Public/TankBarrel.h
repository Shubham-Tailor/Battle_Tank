// Shubham Tailor @Shubham-Tailor Copyright All Right Reserved .2021

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegreePerSecond{ 10.0f };

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MinElevationDegrees{ 0.f };

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxElevationDegrees{ 40.f };
};
