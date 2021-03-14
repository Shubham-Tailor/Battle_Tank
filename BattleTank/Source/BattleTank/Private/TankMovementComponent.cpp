// Shubham Tailor @Shubham-Tailor Copyright All Right Reserved .2021

#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("Intend Move Forward Throw : %f"),Throw);
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::Initialize(UTankTrack* LeftTracktoSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTracktoSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTracktoSet;
	RightTrack = RightTrackToSet;
	// TODO prevent Double Speed from Different simultaneous Key input 
}
