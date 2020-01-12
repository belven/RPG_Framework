// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RPGFrameworkPlayerController.generated.h"

UCLASS()
class ARPGFrameworkPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ARPGFrameworkPlayerController();

protected:
	AActor * actorUnderCursor;
	
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	FHitResult GetHitFromCursor(ECollisionChannel channel = ECollisionChannel::ECC_Pawn);
	virtual void SetupInputComponent() override;
	void InteractWithTarget();
	// End PlayerController interface
	
	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
};


