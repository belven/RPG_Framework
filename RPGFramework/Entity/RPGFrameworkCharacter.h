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
		FString GetCharacterName() { return name; }

	UFUNCTION(BlueprintCallable, Category = "Name")
		void SetCharacterName(FString val);

	UFUNCTION(BlueprintCallable, Category = "Health")
		float GetCurrentHealth();

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
		UStat* GetStatByName(FString name);
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

	UGroup* group;

	TArray<UStat*> stats;

	UPROPERTY(EditAnywhere, Category = "Name")
		FString name;

	UFUNCTION(BlueprintCallable, Category = "Stats")
		void MaximiseStats();
};

