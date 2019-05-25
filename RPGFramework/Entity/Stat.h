// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Stat.generated.h"

UCLASS()
class RPGFRAMEWORK_API UStat : public UObject
{
	GENERATED_BODY()

private:
	FText statName;
	float currentValue;
	float maxValue;
	float minValue;

public:
	UStat();

	UFUNCTION(BlueprintCallable, Category = "Stat")
		static UStat* CreateStat(FText newStatName, float newCurrentValue, float newMaxValue);

	UFUNCTION(BlueprintCallable, Category = "Stat")
		FText GetStatName() { return statName; }

	UFUNCTION(BlueprintCallable, Category = "Stat")
		void SetStatName(FText val) { statName = val; }

	UFUNCTION(BlueprintCallable, Category = "Stat")
		float GetCurrentValue() { return currentValue; }

	UFUNCTION(BlueprintCallable, Category = "Stat")
		void SetCurrentValue(float val);

	UFUNCTION(BlueprintCallable, Category = "Stat")
		float GetMaxValue() { return maxValue; }

	UFUNCTION(BlueprintCallable, Category = "Stat")
		void SetMaxValue(float val) { maxValue = val; }

	UFUNCTION(BlueprintCallable, Category = "Stat")
		float GetMinValue() { return minValue; }

	UFUNCTION(BlueprintCallable, Category = "Stat")
		void SetMinValue(float val) { minValue = val; }
};