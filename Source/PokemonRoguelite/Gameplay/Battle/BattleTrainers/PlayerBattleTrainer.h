// Copyright Falling Snow Interactive 2023

#pragma once

#include "CoreMinimal.h"
#include "BattleTrainer.h"
#include "PlayerBattleTrainer.generated.h"

/**
 * 
 */
UCLASS()
class POKEMONROGUELITE_API APlayerBattleTrainer : public ABattleTrainer
{
	GENERATED_BODY()

public:
	virtual void RequestAction() override;

	virtual void UsePokemon() override;

protected:
	virtual void ActionSelected(UBattleAction* SelectedAction) override;
};
