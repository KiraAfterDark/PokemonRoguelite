// Copyright Falling Snow Interactive 2023

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PokemonRoguelite/Gameplay/Battle/BattleActions/AttackAction.h"
#include "PokemonRoguelite/Gameplay/Battle/BattleTrainers/BattleTrainer.h"
#include "RequestActionUi.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class POKEMONROGUELITE_API URequestActionUi : public UUserWidget
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent)
    void StartActionRequest(ABattleTrainer* BattleTrainer);

    UFUNCTION(BlueprintCallable)
    void ActionSelected(UBattleAction* SelectedAction);
};
