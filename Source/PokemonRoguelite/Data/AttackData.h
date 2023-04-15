// Copyright Falling Snow Interactive 2023

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AttackData.generated.h"

/**
 * 
 */
UCLASS()
class POKEMONROGUELITE_API UAttackData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Information")
	FName Name = "Attack";

	UPROPERTY(EditDefaultsOnly, Category="Stats")
	int Power = 100;
};
