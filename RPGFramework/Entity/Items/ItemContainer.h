// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.h"
#include "ItemContainer.generated.h"

class UDataTable;

UCLASS()
class RPGFRAMEWORK_API UItemContainer : public UObject
{
	GENERATED_BODY()
public:
	TArray<FItemSpecification*> GetItemSpecifications();

	UFUNCTION(BlueprintCallable, Category = "Item")
		TArray<int32>& GetItems() { return items; }

	static UItem* LoadItem(int32 itemID);

private:
	TArray<int32> items;
};

