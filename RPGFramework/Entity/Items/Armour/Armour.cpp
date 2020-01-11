// Fill out your copyright notice in the Description page of Project Settings.

#include "Armour.h"

UArmour* UArmour::CreateArmour(int32 itemID, FItemSpecification armourItemSpecification)
{
	UArmour* armour = NewObject<UArmour>();
	armour->SetItemSpecification(armourItemSpecification);

	GetArmourSpecification(itemID, armour);
	
	for (FArmourSpecification* armourSpec : UDataTables::GetInstance()->GetArmour()) {
		if (armourSpec->itemID == itemID) {
			armour->SetArmourSpecification(armourSpec);
		}
	}

	return armour;
}

void UArmour::GetArmourSpecification(int32 itemID, UArmour* armour)
{
	static const FString ContextString(TEXT("GENERAL"));
	FName armourIDText = *FString::Printf(TEXT("%d"), itemID);

	UDataTable* armourTable = UDataTables::GetInstance()->GetArmourTable();

	for (FName armourID : armourTable->GetRowNames()) {
		FArmourSpecification* armourSpec = armourTable->FindRow<FArmourSpecification>(armourID, ContextString, true);

		if (armourSpec != nullptr) {
			if (armourSpec->itemID == itemID) {
				armour->SetArmourSpecification(armourSpec);
				GetArmourValuesForArmour(armour, armourID);
				break;
			}
		}
	}
}

void UArmour::GetArmourValuesForArmour(UArmour* armour, FName armourID)
{
	int32 armourIDint = FCString::Atoi(*armourID.ToString());

	for (FArmourValue* armourValue : UDataTables::GetInstance()->GetArmourValues()) {
		if (armourValue->armourID == armourIDint) {
			armour->GetArmourValues().Add(armourValue);
		}
	}
}
