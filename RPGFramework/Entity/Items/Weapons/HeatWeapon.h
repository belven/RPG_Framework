// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Entity/Items/Weapons/Weapon.h"
#include "HeatWeapon.generated.h"

/**
 * 
 */
UCLASS()
class RPGFRAMEWORK_API UHeatWeapon : public UWeapon
{
	GENERATED_BODY()

private:
	FHeatWeaponSpecification heatWeaponSpecification;
	
};
