// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemContainer.generated.h"

class UItem;

UCLASS()
class RPGFRAMEWORK_API UItemContainer : public UObject
{
	GENERATED_BODY()
public:
	TArray<UItem*> items;
	
};
