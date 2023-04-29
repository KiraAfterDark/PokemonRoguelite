// Copyright Falling Snow Interactive 2023


#include "PlayerBattleTrainer.h"

void APlayerBattleTrainer::RequestAction()
{
    BattleUi->BattleActionSelected.AddDynamic(this, &APlayerBattleTrainer::ActionSelected);
    BattleUi->RequestAction(this);
}

void APlayerBattleTrainer::ActionSelected(UBattleAction* SelectedAction)
{
    BattleUi->BattleActionSelected.RemoveDynamic(this, &APlayerBattleTrainer::ActionSelected);
    TrainerActionSelected.Broadcast(SelectedAction);
}

void APlayerBattleTrainer::UsePokemon()
{
    Super::UsePokemon();

    BattleUi->DisplayPlayerPokemonInfo(Pokemon);
}