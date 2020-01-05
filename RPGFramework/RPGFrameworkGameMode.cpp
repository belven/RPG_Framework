// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "RPGFrameworkGameMode.h"
#include "Controllers/RPGFrameworkPlayerController.h"
#include "Entity/RPGFrameworkCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "UI/RPGHUD.h"
#include <Kismet/GameplayStatics.h>

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

	static ConstructorHelpers::FClassFinder<AHUD> hud(TEXT("Blueprint'/Game/TopDownCPP/UI/MainHUD.MainHUD_C'"));
	HUDClass = hud.Class;
}

void ARPGFrameworkGameMode::BeginPlay()
{
	Super::BeginPlay();

	ARPGFrameworkCharacter* player = Cast<ARPGFrameworkCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (player != NULL) {
		//hudWidget = CreateWidget<UUserWidget>(GetWorld(), HUDClass);
	}
}
