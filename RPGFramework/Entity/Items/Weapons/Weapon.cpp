// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "DataTables.h"
#include <Engine/DataTable.h>
#include "HeatWeapon.h"
#include "../../RPGFrameworkCharacter.h"


UWeapon* UWeapon::CreateWeapon(int32 itemID, FItemSpecification itemSpecification)
{
	UWeapon* weapon = nullptr;

	static const FString ContextString(TEXT("GENERAL"));

	UDataTable* weaponTable = UDataTables::GetInstance()->GetWeaponTable();

	for (FName weaponID : weaponTable->GetRowNames()) {
		FWeaponSpecification* weaponSpec = weaponTable->FindRow<FWeaponSpecification>(weaponID, ContextString, true);

		int32 weaponDint = FCString::Atoi(*weaponID.ToString());

		if (weaponSpec != nullptr) {
			if (weaponSpec->itemSpecificationID == itemID) {
				switch (weaponSpec->weaponType) {
				case EWeaponType::NORMAL: {
					weapon = NewObject<UWeapon>();
					weapon->SetItemSpecification(itemSpecification);
					weapon->SetWeaponSpecification(weaponSpec);
					break;
				}
				case EWeaponType::AMMO: {
				}
				case EWeaponType::HEAT: {
					weapon = UHeatWeapon::CreateHeatWeapon(weaponDint);
					break;
				}
				}
				break;
			}
		}
	}

	return weapon;
}

bool UWeapon::CanAttack() {
	return true;
}

void UWeapon::FireWeapon(ARPGFrameworkCharacter* target)
{
	// Need to set up timers here to manage use rate
	// Need to pass in damage type
	target->ChangeHealth(weaponSpecification->healthChange, weaponSpecification->heals);
}

void UWeapon::AttackTarget(ARPGFrameworkCharacter* target)
{
	if (CanAttack()) {
		FireWeapon(target);
	}
}
