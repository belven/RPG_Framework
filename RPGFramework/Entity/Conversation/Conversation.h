// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Conversation.generated.h"

USTRUCT(BlueprintType)
struct FDialogLink : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	int32 parentDialogID;
	int32 childDialogID;
};

USTRUCT(BlueprintType)
struct FDialog : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	int32 dialogID;
	FText name;
	FText dialogText;
};

USTRUCT(BlueprintType)
struct FConversationDialog : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	int32 conversationID;
	int32 dialogID;
};

USTRUCT(BlueprintType)
struct FConversationData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	int32 ID;
	FText name;
	FText ConversationText;
};

/**
 *
 */
UCLASS()
class RPGFRAMEWORK_API UConversation : public UObject
{
	GENERATED_BODY()
public:

private:
	FConversationData data;

};
