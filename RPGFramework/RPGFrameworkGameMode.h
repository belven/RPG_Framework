// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include <UserWidget.h>
#include "RPGFrameworkGameMode.generated.h"

UCLASS(minimalapi)
class ARPGFrameworkGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ARPGFrameworkGameMode();
	void BeginPlay() override;
private:
	UUserWidget * hudWidget;
};



