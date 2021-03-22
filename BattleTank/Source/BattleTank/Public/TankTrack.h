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

private:
	float CurrentThrottle{ 0.0f };
	UTankTrack();
	virtual void BeginPlay() override;
	void ApplySidewaysForce();
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	void DriveTrack();
	UPROPERTY(EditDefaultsOnly)
	float MaxTrackDrivingForce{ 400000.f };
};
