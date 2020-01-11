#include "DataTables.h"

UDataTables* UDataTables::INSTANCE;

UDataTables::UDataTables()
{
	static ConstructorHelpers::FObjectFinder<UDataTable>
		itemTable_BP(TEXT("CompositeDataTable'/Game/TopDownCPP/Datatables/ItemTable.ItemTable'"));

	SetItemTable(itemTable_BP.Object);

	static ConstructorHelpers::FObjectFinder<UDataTable>
		weaponTable_BP(TEXT("DataTable'/Game/TopDownCPP/Datatables/WeaponsTable.WeaponsTable'"));

	SetWeaponTable(weaponTable_BP.Object);

	static ConstructorHelpers::FObjectFinder<UDataTable>
		loadoutTable_BP(TEXT("DataTable'/Game/TopDownCPP/Datatables/Loadouts.Loadouts'"));

	SetLoadoutTable(loadoutTable_BP.Object);

	static ConstructorHelpers::FObjectFinder<UDataTable>
		armourTable_BP(TEXT("DataTable'/Game/TopDownCPP/Datatables/Armour.Armour'"));

	SetArmourTable(armourTable_BP.Object);

	static ConstructorHelpers::FObjectFinder<UDataTable>
		armourValuesTable_BP(TEXT("DataTable'/Game/TopDownCPP/Datatables/ArmourValues.ArmourValues'"));

	SetArmourValuesTable(armourValuesTable_BP.Object);

	static ConstructorHelpers::FObjectFinder<UDataTable>
		heatWeaponsTable_BP(TEXT("DataTable'/Game/TopDownCPP/Datatables/HeatWeapons.HeatWeapons'"));

	SetHeatWeaponTable(heatWeaponsTable_BP.Object);

	static ConstructorHelpers::FObjectFinder<UDataTable>
		ammoWeaponsTable_BP(TEXT("DataTable'/Game/TopDownCPP/Datatables/AmmoWeapons.AmmoWeapons'"));

	SetAmmoWeaponTable(ammoWeaponsTable_BP.Object);
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

TArray<FHeatWeaponSpecification*> UDataTables::GetHeatWeapons()
{
	TArray<FHeatWeaponSpecification*> weapons;
	GetHeatWeaponTable()->GetAllRows<FHeatWeaponSpecification>(TEXT("Test"), weapons);
	return weapons;
}

TArray<FAmmoWeaponSpecification*> UDataTables::GetAmmoWeapons()
{
	TArray<FAmmoWeaponSpecification*> weapons;
	GetAmmoWeaponTable()->GetAllRows<FAmmoWeaponSpecification>(TEXT("Test"), weapons);
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
	GetLoadoutTable()->GetAllRows<FLoadout>(TEXT("Test"), loadouts);
	return loadouts;
}
