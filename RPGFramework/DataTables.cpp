#include "DataTables.h"

UDataTables* UDataTables::INSTANCE;

UDataTables::UDataTables()
{
	static ConstructorHelpers::FObjectFinder<UDataTable>
		itemTable_BP(TEXT("CompositeDataTable'/Game/TopDownCPP/Datatables/ItemTable.ItemTable'"));

	if (GetItemTable() == NULL)
		SetItemTable(itemTable_BP.Object);

	static ConstructorHelpers::FObjectFinder<UDataTable>
		weaponTable_BP(TEXT("DataTable'/Game/TopDownCPP/Datatables/WeaponsTable.WeaponsTable'"));

	if (GetWeaponTable() == NULL)
		SetWeaponTable(weaponTable_BP.Object);
}

UDataTables* UDataTables::GetInstance()
{
	if (INSTANCE == nullptr)
	{
		INSTANCE = NewObject<UDataTables>();
	}

	return INSTANCE;
}

TArray<FItemSpecification*> UDataTables::GetItems()
{
	TArray<FItemSpecification*> items;
	GetItemTable()->GetAllRows<FItemSpecification>(TEXT("Test"), items);
	return items;
}

TArray<FWeaponSpecification*> UDataTables::GetWeapons()
{
	TArray<FWeaponSpecification*> weapons;
	GetWeaponTable()->GetAllRows<FWeaponSpecification>(TEXT("Test"), weapons);
	return weapons;
}

TArray<FArmourSpecification*> UDataTables::GetArmour()
{
	TArray<FArmourSpecification*> armour;
	GetArmourTable()->GetAllRows<FArmourSpecification>(TEXT("Test"), armour);
	return armour;
}

TArray<FArmourValue*> UDataTables::GetArmourValues()
{
	TArray<FArmourValue*> armourValues;
	GetArmourValuesTable()->GetAllRows<FArmourValue>(TEXT("Test"), armourValues);
	return armourValues;
}

TArray<FLoadout*> UDataTables::GetLoadouts()
{
	TArray<FLoadout*> loadouts;
	GetItemTable()->GetAllRows<FLoadout>(TEXT("Test"), loadouts);
	return loadouts;
}
