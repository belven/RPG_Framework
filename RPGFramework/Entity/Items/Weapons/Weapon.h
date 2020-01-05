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
	FWeaponSpecification weaponSpecification;
	static FWeaponSpecification* GetWeaponSpecificationForItem(int32 itemID);

public:
	UFUNCTION(BlueprintCallable, Category = "Weapon Specification")
		FWeaponSpecification GetWeaponSpecification();

	UFUNCTION(BlueprintCallable, Category = "Weapon Specification")
		void SetWeaponSpecification(FWeaponSpecification val) { weaponSpecification = val; }

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		static UWeapon* CreateWeapon(int32 itemID, FItemSpecification weaponSpecification);
};