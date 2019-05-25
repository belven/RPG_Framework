// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "RPGFrameworkGameMode.h"
#include "Controllers/RPGFrameworkPlayerController.h"
#include "Entity/RPGFrameworkCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "UI/RPGHUD.h"

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

	static ConstructorHelpers::FClassFinder<AHUD> hud(TEXT("/Game/TopDown/Blueprints/UI/MainHUD.MainHUD_C"));
	// set default pawn class to our character class
	HUDClass = hud.Class;
}