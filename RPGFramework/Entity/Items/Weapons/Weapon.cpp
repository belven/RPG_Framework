// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include <Engine/DataTable.h>

UDataTable* UWeapon::weaponTable;

FWeaponSpecification* UWeapon::GetWeaponSpecificationForItem(int32 itemID)
{
	static const FString ContextString(TEXT("GENERAL"));
	FName weaponIDText = *FString::Printf(TEXT("%d"), itemID);

	TArray<FWeaponSpecification*> rows;
	weaponTable->GetAllRows<FWeaponSpecification>(ContextString, rows);

	for (FWeaponSpecification* weaponSpec : rows) {
		if (weaponSpec->itemSpecificationID == itemID)
			return weaponSpec;
	}

	return nullptr;
}

FWeaponSpecification UWeapon::GetWeaponSpecification()
{
	return weaponSpecification;
}

UWeapon* UWeapon::CreateWeapon(int32 itemID, FItemSpecification weaponSpecification)
{
	UWeapon* weapon = NewObject<UWeapon>();
	GetWeaponSpecificationForItem(itemID);

	weapon->SetItemSpecification(weaponSpecification);
	return weapon;
}
