// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RPGFrameworkCharacter.generated.h"

UCLASS(Blueprintable)
class ARPGFrameworkCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ARPGFrameworkCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }


	UFUNCTION(BlueprintCallable, Category = "Name")
		FString GetName() { return name; }

	UFUNCTION(BlueprintCallable, Category = "Name")
		void SetName(FString val) { name = val; }

	UFUNCTION(BlueprintCallable, Category = "Health")
		float GetCurrentHealth() { return currentHealth; }

	UFUNCTION(BlueprintCallable, Category = "Health")
		void SetCurrentHealth(float val) { currentHealth = val; }

	UFUNCTION(BlueprintCallable, Category = "Health")
		float GetMaxHealth() { return maxHealth; }

	UFUNCTION(BlueprintCallable, Category = "Health")
		void SetMaxHealth(float val) { maxHealth = val; }

	UFUNCTION(BlueprintCallable, Category = "Shield")
		float GetCurrentShield() { return currentShield; }

	UFUNCTION(BlueprintCallable, Category = "Shield")
		void SetCurrentShield(float val) { currentShield = val; }

	UFUNCTION(BlueprintCallable, Category = "Shield")
		float GetMaxShield() { return maxShield; }

	UFUNCTION(BlueprintCallable, Category = "Shield")
		void SetMaxShield(float val) { maxShield = val; }
private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UDecalComponent* CursorToWorld;

	UPROPERTY(EditAnywhere, Category = "Name")
		FString name;

	UPROPERTY(EditAnywhere, Category = "Health")
		float currentHealth;

	UPROPERTY(EditAnywhere, Category = "Health")
		float maxHealth;

	UPROPERTY(EditAnywhere, Category = "Shield")
		float currentShield;

	UPROPERTY(EditAnywhere, Category = "Shield")
		float maxShield;

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void MaximiseStats();
};

