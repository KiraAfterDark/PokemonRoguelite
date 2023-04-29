// Copyright Falling Snow Interactive 2023

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PaperSprite.h"
#include "Pokemons/PokemonInstanceData.h"
#include "TrainerData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class POKEMONROGUELITE_API UTrainerData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Information")
	FName Name;

	UPROPERTY(EditDefaultsOnly, Category="Visuals")
	UPaperSprite* FrontSprite;

	UPROPERTY(EditDefaultsOnly, Category="Party")
	TArray<UPokemonInstanceData*> PartyData;
	
};
