// Shubham Tailor @Shubham-Tailor Copyright All Right Reserved .2021

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}

void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if ((GetWorld()->GetTimeSeconds() - LastFireTime) < ReloadTime)
	{
		FiringState = EFiringState::Reloading;
	}
	else if (IsBarrelMoving())
	{
		FiringState = EFiringState::Locked;
	}
	else
	{
		FiringState = EFiringState::Aiming;
	}
}

void UTankAimingComponent::BeginPlay() 
{
	LastFireTime = GetWorld()->GetTimeSeconds();
}

void UTankAimingComponent::Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!ensure (Barrel)) { return; }
	
	FVector LaunchVelocity{0};
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	// Calculate the OutLaunchVelocity
	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		LaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
		))
	{
		AimDirection = LaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
	// if not Found do nothing
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirectionVector)
{
	if (!ensure (Turret && Barrel)) { return; }
	// Decide Yaw, Pitch and Roll through AimDirectionVector of barrel
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirectionVector.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Turret->Rotate(DeltaRotator.Yaw);
	Barrel->Elevate(DeltaRotator.Pitch);
}

bool UTankAimingComponent::IsBarrelMoving()
{
	if (!ensure(Barrel)) { return false; }
	auto BarrelForward = Barrel->GetForwardVector();
	return (BarrelForward.Equals(AimDirection, 0.01));
}

void UTankAimingComponent::Fire()
{
	if (FiringState != EFiringState::Reloading) {
		//Spawn a projectile at the socket location on the barrel
		if (!ensure (ProjectileBlueprint)) { return; }
		if (!ensure (Barrel)) { return; }
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		Projectile->LaunchProjectile(LaunchSpeed);
	}
	LastFireTime = GetWorld()->GetTimeSeconds();
}