// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Entity/Items/Item.h"
#include "DataTables.h"
#include "Armour.generated.h"

/**
 *
 */
UCLASS()
class RPGFRAMEWORK_API UArmour : public UItem
{
	GENERATED_BODY()

public:
	static UArmour* CreateArmour(int32 itemID, FItemSpecification armourSpecification);

	static void GetArmourSpecification(int32 itemID, UArmour* armour);

	FArmourSpecification* GetArmourSpecification() { return armourSpecification; }
	void SetArmourSpecification(FArmourSpecification* val) { armourSpecification = val; }

	TArray<FArmourValue *>& GetArmourValues() { return armourValues; }
private:
	FArmourSpecification * armourSpecification;
	TArray<FArmourValue*> armourValues;
	static void GetArmourValuesForArmour(UArmour* armour, FName armourID);
};
