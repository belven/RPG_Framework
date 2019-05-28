// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Items/Weapons/Weapon.h"
#include "Engine/DataTable.h"
#include "Loadout.generated.h"

USTRUCT(BlueprintType)
struct FLoadout : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loadout")
		float maxHealth = 2000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loadout")
		float maxSpeed = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loadout")
		TArray<int32> weaponIDs;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loadout")
		FWeaponSpecification weaponSpecification;
};

UCLASS()
class RPGFRAMEWORK_API ULoadoutFunctions : public UObject
{
	GENERATED_BODY()
public:
	FORCEINLINE static void CreateLoadout(int loadoutID) {

	}

};