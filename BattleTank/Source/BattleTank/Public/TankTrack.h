// Shubham Tailor @Shubham-Tailor Copyright All Right Reserved .2021

#pragma once

#include "CoreMinimal.h"
#include "Components/MeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
};
