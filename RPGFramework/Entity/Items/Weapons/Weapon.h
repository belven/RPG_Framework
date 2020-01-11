// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataTables.h"
#include "../Item.h"
#include "Weapon.generated.h"

UCLASS()
class RPGFRAMEWORK_API UWeapon : public UItem
{
	GENERATED_BODY()

private:
	FWeaponSpecification * weaponSpecification;

public:
	static UWeapon* CreateWeapon(int32 itemID, FItemSpecification weaponSpecification);

	FWeaponSpecification * GetWeaponSpecification() { return weaponSpecification; }

	void SetWeaponSpecification(FWeaponSpecification * val) { weaponSpecification = val; }
};