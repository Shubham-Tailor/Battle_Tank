// Shubham Tailor @Shubham-Tailor Copyright All Right Reserved .2021


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	// TODO clamp throttle value so player cannot override
	auto ForceApplied = GetForwardVector() * Throttle * MaxTrackDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
