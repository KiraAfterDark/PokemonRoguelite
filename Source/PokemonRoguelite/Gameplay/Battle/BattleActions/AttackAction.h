// Copyright Falling Snow Interactive 2023

#pragma once

#include "CoreMinimal.h"
#include "BattleAction.h"
#include "PokemonRoguelite/Data/AttackData.h"
#include "PokemonRoguelite/Gameplay/Battle/BattlePokemon.h"
#include "AttackAction.generated.h"

/**
 * Priority index (Higher priority goes first)
 * 0 - None
 * 1 - Attack
 * 3 - Item
 * 4 - Switch
 * 5 - Run
 */
UCLASS(BlueprintType)
class POKEMONROGUELITE_API UAttackAction : public UBattleAction
{
    GENERATED_BODY()

private:
    UPROPERTY()
    UAttackData* Attack;

    UPROPERTY()
    ABattlePokemon* Attacker;

    UPROPERTY()
    ABattlePokemon* Defender;

public:
    virtual float GetPriority() override;
};
