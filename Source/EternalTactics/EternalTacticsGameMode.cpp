// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "EternalTactics.h"
#include "EternalTacticsGameMode.h"
#include "EternalTacticsPlayerController.h"
#include "EternalTacticsCharacter.h"

AEternalTacticsGameMode::AEternalTacticsGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AEternalTacticsPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}