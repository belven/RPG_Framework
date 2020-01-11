// Fill out your copyright notice in the Description page of Project Settings.


#include "HeatWeapon.h"

UHeatWeapon* UHeatWeapon::CreateHeatWeapon(int32 weaponID)
{
	UHeatWeapon* heatWeapon = NewObject<UHeatWeapon>();
	FHeatWeaponSpecification* heatSpec = nullptr;

	for (FHeatWeaponSpecification* spec : UDataTables::GetInstance()->GetHeatWeapons()) {
		if (spec->weaponSpecificationID == weaponID) {
			heatSpec = spec;
			break;
		}
	}

	if (heatSpec != nullptr) {
		heatWeapon->SetHeatWeaponSpecification(heatSpec);
	}

	return heatWeapon;
}
