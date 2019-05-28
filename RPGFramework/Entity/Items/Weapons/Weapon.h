// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Entity/Items/Item.h"
#include "Engine/DataTable.h"
#include "Weapon.generated.h"

UENUM(BlueprintType)
enum class  EWeaponType : uint8 {
	NORMAL,
	AMMO,
	HEAT
};


USTRUCT(BlueprintType)
struct FWeaponSpecification : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Specification")
		int itemSpecificationID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Specification")
		EWeaponType weaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Specification")
		float useRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Specification")
		float healthChange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Specification")
		float range;
};

USTRUCT(BlueprintType)
struct FAmmoWeaponSpecification : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Specification")
		int weaponSpecificationID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Specification")
		float maxAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Specification")
		float reloadSpeed;
};

USTRUCT(BlueprintType)
struct FHeatWeaponSpecification : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Specification")
		int weaponSpecificationID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Specification")
		float maxHeat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Specification")
		float heatGenerated;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Specification")
		float passiveHeatLoss;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Specification")
		float overheatCooldown;
};

UCLASS()
class RPGFRAMEWORK_API UWeapon : public UItem
{
	GENERATED_BODY()

private:
	FWeaponSpecification weaponSpecification;

public:

	UFUNCTION(BlueprintCallable, Category = "Weapon Specification")
		FWeaponSpecification GetWeaponSpecification();

	UFUNCTION(BlueprintCallable, Category = "Weapon Specification")
		void SetWeaponSpecification(FWeaponSpecification val) {  }
};