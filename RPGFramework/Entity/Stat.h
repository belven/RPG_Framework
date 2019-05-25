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
	FString statName;
	float currentValue;
	float maxValue;
	
public:

	UFUNCTION(BlueprintCallable, Category = "Stat")
		FString GetStatName() { return statName; }

	UFUNCTION(BlueprintCallable, Category = "Stat")
		void SetStatName(FString val) { statName = val; }
};



