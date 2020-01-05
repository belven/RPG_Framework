// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ItemContainer.h"
#include "DataTables.h"
#include "Weapons/Weapon.h"
#include "Armour/Armour.h"
#include <Engine/DataTable.h>

TArray<FItemSpecification*> UItemContainer::GetItemSpecifications()
{
	return UDataTables::GetInstance()->GetItems();
}

UItem* UItemContainer::LoadItem(int32 itemID)
{
	static const FString ContextString(TEXT("GENERAL"));
	FName itemIDText = *FString::Printf(TEXT("%d"), itemID);

	FItemSpecification* itemSpecification = UDataTables::GetInstance()->GetItemTable()->FindRow<FItemSpecification>(
		itemIDText, ContextString);

	if (itemSpecification) {
		switch (itemSpecification->itemType) {
		case EItemType::NORMAL:
			return UItem::CreateItem(itemID, *itemSpecification);
		case EItemType::WEAPON:
			return UWeapon::CreateWeapon(itemID, *itemSpecification);
		case EItemType::ARMOUR:
			return UArmour::CreateArmour(itemID, *itemSpecification);
		default:
			break;
		}
	}

	return nullptr;
}