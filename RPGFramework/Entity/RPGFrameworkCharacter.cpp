// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "RPGFrameworkCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "Items/ItemContainer.h"

#include "Group.h"
#include "Stat.h"
#include "DataTables.h"
#include "Items/Weapons/Weapon.h"
#include "Items/Armour/Armour.h"

const FText ARPGFrameworkCharacter::healthStatName = GetTextFromLiteral(TEXT("Health"));

ARPGFrameworkCharacter::ARPGFrameworkCharacter()
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
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Create a decal in the world to show the cursor's location
	CursorToWorld = CreateDefaultSubobject<UDecalComponent>("CursorToWorld");
	CursorToWorld->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UMaterial> DecalMaterialAsset(TEXT("Material'/Game/TopDownCPP/Blueprints/M_Cursor_Decal.M_Cursor_Decal'"));
	if (DecalMaterialAsset.Succeeded())
	{
		CursorToWorld->SetDecalMaterial(DecalMaterialAsset.Object);
	}
	CursorToWorld->DecalSize = FVector(16.0f, 32.0f, 32.0f);
	CursorToWorld->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f).Quaternion());

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	AddStat(UStat::CreateStat(ARPGFrameworkCharacter::healthStatName, 1000, 1000));

	MaximiseStats();

	this->ID = 0;

	/*for (FItemSpecification* spec : UDataTables::GetInstance()->GetItems()) {
		UE_LOG(LogTemp, Warning, TEXT("%s"), *spec->name.ToString());
	}*/
}

void ARPGFrameworkCharacter::BeginPlay()
{
	this->SetupWithLoadout(0);
}

void ARPGFrameworkCharacter::SetupWithLoadout(int32 loadoutID) {
	FLoadout* ourloadout = nullptr;

	for (FLoadout* loadout : UDataTables::GetInstance()->GetLoadouts()) {
		if (loadout->characterID == this->ID) {
			ourloadout = loadout;
			break;
		}
	}

	if (ourloadout != nullptr) {
		SetMaxHealth(ourloadout->maxHealth);

		for (TPair<EPosition, int32>& weaponPosition : ourloadout->equippedWeapons) {
			TPair<EPosition, UWeapon*> weaponPair;
			weaponPair.Key = weaponPosition.Key;
			weaponPair.Value = Cast<UWeapon>(UItemContainer::LoadItem(weaponPosition.Value));

			GetWeapons().Add(weaponPair);
		}

		for (int32 armourID : ourloadout->equippedArmour) {
			UArmour* armourFound = Cast<UArmour>(UItemContainer::LoadItem(armourID));

			if (armourFound != nullptr) {
				TPair<EPosition, UArmour*> armourPair;
				armourPair.Key = armourFound->GetArmourSpecification()->armourPosition;
				armourPair.Value = armourFound;

				GetArmour().Add(armourPair);
			}
		}

		MaximiseStats();
	}
}

void ARPGFrameworkCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (CursorToWorld != nullptr)
	{
		if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
		{
			if (UWorld* World = GetWorld())
			{
				FHitResult HitResult;
				FCollisionQueryParams Params(NAME_None, FCollisionQueryParams::GetUnknownStatId());
				FVector StartLocation = TopDownCameraComponent->GetComponentLocation();
				FVector EndLocation = TopDownCameraComponent->GetComponentRotation().Vector() * 2000.0f;
				Params.AddIgnoredActor(this);
				World->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, Params);
				FQuat SurfaceRotation = HitResult.ImpactNormal.ToOrientationRotator().Quaternion();
				CursorToWorld->SetWorldLocationAndRotation(HitResult.Location, SurfaceRotation);
			}
		}
		else if (APlayerController* PC = Cast<APlayerController>(GetController()))
		{
			FHitResult TraceHitResult;
			PC->GetHitResultUnderCursor(ECC_Visibility, true, TraceHitResult);
			FVector CursorFV = TraceHitResult.ImpactNormal;
			FRotator CursorR = CursorFV.Rotation();
			CursorToWorld->SetWorldLocation(TraceHitResult.Location);
			CursorToWorld->SetWorldRotation(CursorR);
		}
	}
}

UStat* ARPGFrameworkCharacter::GetStatByName(FText statName)
{
	for (UStat* stat : stats) {
		if (stat->GetStatName().EqualTo(statName))
			return stat;
	}
	return NewObject<UStat>();
}

float ARPGFrameworkCharacter::GetCurrentHealth()
{
	return GetHealthStat()->GetCurrentValue();
}

UStat* ARPGFrameworkCharacter::GetHealthStat()
{
	return GetStatByName(ARPGFrameworkCharacter::healthStatName);
}

FText ARPGFrameworkCharacter::GetTextFromLiteral(FName text)
{
	return FText::FromName(text);
}

void ARPGFrameworkCharacter::SetCurrentHealth(float val)
{
	GetHealthStat()->SetCurrentValue(val);
}

float ARPGFrameworkCharacter::GetMaxHealth()
{
	return GetHealthStat()->GetMaxValue();
}

void ARPGFrameworkCharacter::SetMaxHealth(float val)
{
	GetHealthStat()->SetMaxValue(val);
}
void ARPGFrameworkCharacter::MaximiseStats()
{
	SetCurrentHealth(GetMaxHealth());
}

void ARPGFrameworkCharacter::AddStat(UStat* newStat)
{
	if (GetStatByName(newStat->GetStatName()) == NULL)
		GetStats().Add(newStat);
}