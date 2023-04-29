// Copyright Falling Snow Interactive 2023

#pragma once

#include "CoreMinimal.h"
#include "BattleTrainer.h"
#include "EnemyBattleTrainer.generated.h"

/**
 * 
 */
UCLASS()
class POKEMONROGUELITE_API AEnemyBattleTrainer : public ABattleTrainer
{
	GENERATED_BODY()

public:
    virtual void UsePokemon() override;
};
