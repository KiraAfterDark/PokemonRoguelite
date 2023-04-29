// Copyright Falling Snow Interactive 2023


#include "EnemyBattleTrainer.h"

void AEnemyBattleTrainer::UsePokemon()
{
    Super::UsePokemon();

    BattleUi->DisplayEnemyPokemonInfo(Pokemon);
}
