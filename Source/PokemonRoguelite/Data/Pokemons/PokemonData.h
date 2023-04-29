// Copyright Falling Snow Interactive 2023

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PaperSprite.h"
#include "PokemonType.h"
#include "StatBlock.h"
#include "PokemonRoguelite/Data/AttackData.h"
#include "PokemonData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class POKEMONROGUELITE_API UPokemonData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Information")
	FName Name;

	UPROPERTY(EditDefaultsOnly, Category="Visuals")
	UPaperSprite* FrontSprite;

	UPROPERTY(EditDefaultsOnly, Category="Stats")
	TEnumAsByte<EPokemonType> Type;

	UPROPERTY(EditDefaultsOnly, Category="Stats")
	FStatBlock BaseStats;

	UPROPERTY(EditDefaultsOnly, Category="Attacks")
	TArray<UAttackData*> Attacks;
};
