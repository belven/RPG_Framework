// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

UItem* UItem::CreateItem(int32 itemID, FItemSpecification inItemSpecification)
{
	UItem* item = NewObject<UItem>();
	item->SetItemSpecification(inItemSpecification);
	return item;
}
