// Shubham Tailor @Shubham-Tailor Copyright All Right Reserved .2021

#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	// TODO prevent Double Speed from Different simultaneous Key input 
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::Initialize(UTankTrack* LeftTracktoSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTracktoSet;
	RightTrack = RightTrackToSet;
}
