// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Entity/Items/Item.h"
#include "Engine/DataTable.h"
#include "Weapon.generated.h"

UENUM(BlueprintType)
enum class  EWeaponType : uint8 {
	MELEE_AMMO,
	MELEE,
	RANGED_HEAT,
	RANGED_AMMO,
	RANGED
};

USTRUCT(BlueprintType)
struct FWeaponSpecification : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Specification")
		int weaponSpecificationID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Specification")
		FText weaponName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Specification")
		EWeaponType weaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Specification")
		float useRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Specification")
		float healthChange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Specification")
		float useRange;
};

UCLASS()
class RPGFRAMEWORK_API UWeapon : public UItem
{
	GENERATED_BODY()

private:
	FWeaponSpecification weaponSpecification;

public:

	UFUNCTION(BlueprintCallable, Category = "Weapon Specification")
		FWeaponSpecification GetWeaponSpecification() { return weaponSpecification; }

	UFUNCTION(BlueprintCallable, Category = "Weapon Specification")
		void SetWeaponSpecification(FWeaponSpecification val) { weaponSpecification = val; }
};