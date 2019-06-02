// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Entity/Items/Item.h"
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
};
