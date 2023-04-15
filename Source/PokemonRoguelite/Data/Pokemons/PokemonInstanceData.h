// Copyright Falling Snow Interactive 2023

#pragma once

#include "CoreMinimal.h"
#include "PokemonData.h"
#include "Engine/DataAsset.h"
#include "PokemonInstanceData.generated.h"

/**
 * 
 */
UCLASS()
class POKEMONROGUELITE_API UPokemonInstanceData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Pokemon")
	UPokemonData* Data;

	UPROPERTY(EditDefaultsOnly,Category="Pokemon")
	int Level;

	UPROPERTY(EditDefaultsOnly, Category="Pokemon")
	FStatBlock Ivs;
};
