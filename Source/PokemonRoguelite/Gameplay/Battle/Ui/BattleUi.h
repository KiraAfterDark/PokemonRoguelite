// Copyright Falling Snow Interactive 2023

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PokemonRoguelite/Gameplay/Battle/BattlePokemon.h"
#include "PokemonRoguelite/Gameplay/Battle/BattleActions/BattleAction.h"
#include "BattleUi.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBattleActionSelectedUi, UBattleAction*, BattleAction);

/**
 * 
 */
UCLASS()
class POKEMONROGUELITE_API UBattleUi : public UUserWidget
{
	GENERATED_BODY()

public:
    FBattleActionSelectedUi BattleActionSelected;

protected:
    UPROPERTY(BlueprintReadOnly)
    FString Text;

public:
    // Textbox Variables
    void ShowText(FString T);

    UFUNCTION(BlueprintImplementableEvent, Category="Battle")
    void DisplayPlayerPokemonInfo(ABattlePokemon* PlayerPokemon);

    UFUNCTION(BlueprintImplementableEvent, Category="Battle")
    void RemovePlayerPokemonInfo();

    UFUNCTION(BlueprintImplementableEvent, Category="Battle")
    void DisplayEnemyPokemonInfo(ABattlePokemon* EnemyPokemon);

    UFUNCTION(BlueprintImplementableEvent, Category="Battle")
    void RemoveEnemyPokemonInfo();
    
    UFUNCTION(BlueprintImplementableEvent, Category="Battle")
    void DisplayText();

    UFUNCTION(BlueprintImplementableEvent, Category="Battle")
    void HideText();

    // Action Select
    void RequestAction(ABattleTrainer* BattleTrainer);

    UFUNCTION(BlueprintImplementableEvent)
    void StartRequestAction(ABattleTrainer* BattleTrainer);

    UFUNCTION(BlueprintCallable)
    void ActionSelected(UBattleAction* SelectedAction);
};
