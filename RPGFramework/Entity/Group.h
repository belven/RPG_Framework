// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Group.generated.h"

class ARPGFrameworkCharacter;

UCLASS()
class RPGFRAMEWORK_API UGroup : public UObject
{
	GENERATED_BODY()
private:
	TArray<ARPGFrameworkCharacter*> members;

public:
	UFUNCTION(BlueprintCallable, Category = "Group")
		TArray<ARPGFrameworkCharacter *>& GetMembers() { return members; }

	UFUNCTION(BlueprintCallable, Category = "Group")
		void AddMember(ARPGFrameworkCharacter* memberToAdd);

	UFUNCTION(BlueprintCallable, Category = "Group")
		void RemoveMember(ARPGFrameworkCharacter* memberToRemove);

};
