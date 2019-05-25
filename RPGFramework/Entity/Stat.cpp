// Fill out your copyright notice in the Description page of Project Settings.


#include "Stat.h"

UStat::UStat()
{
	statName = FText::FromName(FName(TEXT("Unknown")));
	currentValue = 0;
	maxValue = 0;
	minValue = 0;
}

UStat* UStat::CreateStat(FText newStatName, float newCurrentValue, float newMaxValue)
{
	UStat* newStat = NewObject<UStat>();
	newStat->SetStatName(newStatName);
	newStat->SetCurrentValue(newCurrentValue);
	newStat->SetMaxValue(newMaxValue);
	return newStat;
}

void UStat::SetCurrentValue(float val)
{
	if (val > maxValue) {
		currentValue = maxValue;
	}
	else if (val < minValue) {
		currentValue = minValue;
	}
	else {
		currentValue = val;
	}
}
