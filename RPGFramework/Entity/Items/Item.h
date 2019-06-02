// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Item.generated.h"

UENUM(BlueprintType)
enum class  EItemType : uint8 {
	NORMAL,
	WEAPON,
	ARMOUR
};

USTRUCT(BlueprintType)
struct FItemSpecification : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Specification")
		EItemType itemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Specification")
		FText name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Specification")
		int stackLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Specification")
		float weight;
};

UCLASS()
class RPGFRAMEWORK_API UItem : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "Item Specification")
		FItemSpecification itemSpecification;

public:

	UFUNCTION(BlueprintCallable, Category = "Item Specification")
		FItemSpecification GetItemSpecification() { return itemSpecification; }

	UFUNCTION(BlueprintCallable, Category = "Item Specification")
		void SetItemSpecification(FItemSpecification val) { itemSpecification = val; }

	UFUNCTION(BlueprintCallable, Category = "Item")
		static UItem* CreateItem(int32 itemID, FItemSpecification inItemSpecification);
};
