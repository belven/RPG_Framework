// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "DataTables.h"
#include <Engine/DataTable.h>

FWeaponSpecification* UWeapon::GetWeaponSpecificationForItem(int32 itemID)
{
	static const FString ContextString(TEXT("GENERAL"));
	FName weaponIDText = *FString::Printf(TEXT("%d"), itemID);
	
	for (FWeaponSpecification* weaponSpec : UDataTables::GetInstance()->GetWeapons()) {
		if (weaponSpec->itemSpecificationID == itemID)
			return weaponSpec;
	}

	return nullptr;
}

FWeaponSpecification UWeapon::GetWeaponSpecification()
{
	return weaponSpecification;
}

UWeapon* UWeapon::CreateWeapon(int32 itemID, FItemSpecification itemSpecification)
{
	UWeapon* weapon = NewObject<UWeapon>();
	GetWeaponSpecificationForItem(itemID);

	weapon->SetItemSpecification(itemSpecification);
	return weapon;
}
