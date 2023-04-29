// Copyright Falling Snow Interactive 2023

#pragma once

#include "CoreMinimal.h"
#include "PokemonInstance.h"
#include "PokemonRoguelite/Data/TrainerData.h"
#include "UObject/Object.h"
#include "TrainerInstance.generated.h"

/**
 * 
 */
UCLASS()
class POKEMONROGUELITE_API UTrainerInstance : public UObject
{
    GENERATED_BODY()

private:
    UPROPERTY()
    UTrainerData* Data;

    UPROPERTY()
    TArray<UPokemonInstance*> Party;

public:
    UTrainerInstance();
    
    void Init(UTrainerData* D);

    UPaperSprite* GetBattleSprite() const;
    TArray<UPokemonInstance*> GetParty();

    FName GetName();
};
