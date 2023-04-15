// Copyright Falling Snow Interactive 2023

#pragma once

#include "CoreMinimal.h"
#include "Health.h"
#include "PokemonRoguelite/Data/Pokemons/PokemonData.h"
#include "PokemonRoguelite/Data/Pokemons/PokemonInstanceData.h"
#include "UObject/NoExportTypes.h"
#include "PokemonInstance.generated.h"

/**
 * 
 */
UCLASS()
class POKEMONROGUELITE_API UPokemonInstance final : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	UPokemonData* Data;
	
	UPROPERTY(BlueprintReadOnly)
	FName Name;
	
	UPROPERTY(BlueprintReadOnly)
	int Level;

	UPROPERTY(BlueprintReadOnly)
	TArray<UAttackData*> Attacks;

private:
	UHealth* Health;
	
	FStatBlock Ivs;
	FStatBlock Stats;

public:
	UPokemonInstance();
	
	void Init(UPokemonData* D, int L, FStatBlock I);
	void Init(const UPokemonInstanceData* InstanceData);

	UHealth* GetHealth();
	FStatBlock* GetStats();
	
};
