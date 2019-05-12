// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "RPGFrameworkGameMode.h"
#include "Controllers/RPGFrameworkPlayerController.h"
#include "Entity/RPGFrameworkCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARPGFrameworkGameMode::ARPGFrameworkGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ARPGFrameworkPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}