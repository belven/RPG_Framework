// Fill out your copyright notice in the Description page of Project Settings.


#include "Armour.h"

UArmour* UArmour::CreateArmour(int32 itemID, FItemSpecification armourSpecification)
{
	UArmour* armour = NewObject<UArmour>();
	armour->SetItemSpecification(armourSpecification);
	return armour;
}
