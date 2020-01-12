// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "RPGFrameworkPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Entity/RPGFrameworkCharacter.h"
#include "Engine/World.h"

ARPGFrameworkPlayerController::ARPGFrameworkPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ARPGFrameworkPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	FHitResult Hit;
	Hit = GetHitFromCursor();

	if (Hit.bBlockingHit)
	{
		actorUnderCursor = Hit.GetActor();

		if (actorUnderCursor != nullptr)
		{
			CurrentMouseCursor = EMouseCursor::Crosshairs;
		}
		else
		{
			CurrentMouseCursor = EMouseCursor::Hand;
		}
	}

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}
}

FHitResult ARPGFrameworkPlayerController::GetHitFromCursor(ECollisionChannel channel)
{
	static FHitResult Hit;
	GetHitResultUnderCursor(channel, true, Hit);
	return Hit;
}

void ARPGFrameworkPlayerController::SetupInputComponent()
{
	// set up game play key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ARPGFrameworkPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &ARPGFrameworkPlayerController::OnSetDestinationReleased);

	InputComponent->BindAction("InteractWithTarget", IE_Pressed, this, &ARPGFrameworkPlayerController::InteractWithTarget);
}

void ARPGFrameworkPlayerController::InteractWithTarget() {
	if (actorUnderCursor != nullptr) {
		ARPGFrameworkCharacter* owner = Cast<ARPGFrameworkCharacter>(GetPawn());

		if (owner != nullptr) {
			ARPGFrameworkCharacter* target = Cast<ARPGFrameworkCharacter>(actorUnderCursor);
			if (target != nullptr) {
				owner->InteractWithTarget(target);
			}
		}
	}
}

void ARPGFrameworkPlayerController::MoveToMouseCursor()
{
	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(Hit.ImpactPoint);
	}
}

void ARPGFrameworkPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void ARPGFrameworkPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void ARPGFrameworkPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}
