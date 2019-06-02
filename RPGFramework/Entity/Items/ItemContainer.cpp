// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemContainer.h"
#include "Item.h"
#include "Weapons/Weapon.h"
#include "Armour/Armour.h"
#include <Engine/DataTable.h>

UDataTable* UItemContainer::itemTable = nullptr;

UItemContainer::UItemContainer()
{
	static ConstructorHelpers::FObjectFinder<UDataTable>
		itemTable_BP(TEXT("DataTable'/Game/Data/GameObjectLookup.GameObjectLookup'"));

	if (itemTable == NULL)
		itemTable = itemTable_BP.Object;
}

UItem* UItemContainer::LoadItem(int32 itemID)
{
	static const FString ContextString(TEXT("GENERAL"));
	FName itemIDText = *FString::Printf(TEXT("%d"), itemID);

	FItemSpecification* itemSpecification = itemTable->FindRow<FItemSpecification>(
		itemIDText, ContextString);

	if (itemSpecification) {
		switch (itemSpecification->itemType) {
		case EItemType::NORMAL:
			return UItem::CreateItem(itemID, *itemSpecification);
		case EItemType::WEAPON:
			return UWeapon::CreateWeapon(itemID, *itemSpecification);
		case EItemType::ARMOUR:
			return UArmour::CreateArmour(itemID, *itemSpecification);

		}
	}

	return nullptr;
}

