// Copyright Falling Snow Interactive 2023

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AttackData.generated.h"

/**
 * 
 */

UENUM()
enum EAttackCategory
{
	None,
	Physical,
	Special,
};

UCLASS(BlueprintType)
class POKEMONROGUELITE_API UAttackData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Information")
	FName Name = "Attack";

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Stats")
	int Power = 100;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Category")
	TEnumAsByte<EAttackCategory> AttackCategory;
};
