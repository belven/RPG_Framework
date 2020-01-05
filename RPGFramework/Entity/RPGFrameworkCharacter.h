// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RPGFrameworkCharacter.generated.h"

class UGroup;
class UStat;

UCLASS(Blueprintable)
class ARPGFrameworkCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	static const FText healthStatName;
	ARPGFrameworkCharacter();

	UFUNCTION(BlueprintCallable, Category = "Loadout")
		void SetupWithLoadout(int32 loadoutID);

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

	UFUNCTION(BlueprintCallable, Category = "Health")
		float GetCurrentHealth();

	UFUNCTION(BlueprintCallable, Category = "Health")
		UStat* GetHealthStat();

	UFUNCTION(BlueprintCallable, Category = "Text")
		static FText GetTextFromLiteral(FName text);

	UFUNCTION(BlueprintCallable, Category = "Health")
		void SetCurrentHealth(float val);

	UFUNCTION(BlueprintCallable, Category = "Health")
		float GetMaxHealth();

	UFUNCTION(BlueprintCallable, Category = "Health")
		void SetMaxHealth(float val);

	UFUNCTION(BlueprintCallable, Category = "Group")
		UGroup* GetGroup() { return group; }

	UFUNCTION(BlueprintCallable, Category = "Group")
		void SetGroup(UGroup* val) { group = val; }

	UFUNCTION(BlueprintCallable, Category = "Stats")
		TArray<UStat *>& GetStats() { return stats; }

	UFUNCTION(BlueprintCallable, Category = "Stats")
		UStat* GetStatByName(FText statName);

	UFUNCTION(BlueprintCallable, Category = "Name")
		FText GetCharacterName() { return characterName; }

	UFUNCTION(BlueprintCallable, Category = "Name")
		void SetCharacterName(FText val) { characterName = val; }

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		TMap<EPosition, UWeapon *> GetWeapons() { return weapons; }

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void SetWeapons(TMap<EPosition, UWeapon *> val) { weapons = val; }

	UFUNCTION(BlueprintCallable, Category = "Armour")
		TMap<EPosition, UArmour *> GetArmour() { return armour; }

	UFUNCTION(BlueprintCallable, Category = "Armour")
		void SetArmour(TMap<EPosition, UArmour *> val) { armour = val; }
private:

	UPROPERTY(EditAnywhere, Category = "ID")
		int32 ID;

	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UDecalComponent* CursorToWorld;

	UPROPERTY(EditAnywhere, Category = "Group")
		UGroup* group;

	UPROPERTY(EditAnywhere, Category = "Name")
		TArray<UStat*> stats;

	UPROPERTY(EditAnywhere, Category = "Weapon")
		TMap<EPosition, UWeapon*> weapons;

	UPROPERTY(EditAnywhere, Category = "Armour")
		TMap<EPosition, UArmour*> armour;

	UPROPERTY(EditAnywhere, Category = "Name")
		FText characterName;

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void MaximiseStats();

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void AddStat(UStat* newStat);
};