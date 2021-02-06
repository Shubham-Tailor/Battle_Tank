// Shubham Tailor @Shubham-Tailor Copyright All Right Reserved .2021

#pragma once

#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UStaticMeshComponent* Barrel = nullptr;

public:
	// TODO add SetTurretReference
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed);

	void SetBarrelReference(UStaticMeshComponent* Barrel);

	void MoveBarrelTowards(FVector AimDirection);
};
