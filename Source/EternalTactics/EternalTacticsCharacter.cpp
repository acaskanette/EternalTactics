// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "EternalTactics.h"
#include "EternalTacticsCharacter.h"

AEternalTacticsCharacter::AEternalTacticsCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->AttachTo(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

}



bool AEternalTacticsCharacter::PerformAction(EActionType Action_, int32 APCost_) {
	
	if (CanSpendActionPoints(APCost_)) {

		switch (Action_)
		{
		case EActionType::AT_WALK:
			break;
		case EActionType::AT_RUN:
			break;
		case EActionType::AT_ATTACK:
			break;
		default:
			break;
		}

		SetActionPoints(APCost_);

		return true;

	}

	return false;
	
}


bool AEternalTacticsCharacter::CanSpendActionPoints(int32 APCost_) {
	// Are my current actionPoints good to go?	
	return (actionPoints >= APCost_);
}


void AEternalTacticsCharacter::SetActionPoints(int32 APSpent_) {
	
	// Spend AP
	actionPoints = actionPoints - APSpent_;
	// Don't accidentally go negative
	if (actionPoints < 0)
		actionPoints = 0;

}

void AEternalTacticsCharacter::RefreshActionPoints() {

	// Set Action Points back to maximum
	actionPoints = maxActionPoints;

}
