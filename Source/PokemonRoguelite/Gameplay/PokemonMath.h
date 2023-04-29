#pragma once
#include "Battle/BattlePokemon.h"
#include "PokemonRoguelite/Data/AttackData.h"

class PokemonMath
{
public:
    static int CalculateDamage(UAttackData* Attack, ABattlePokemon* Attacker, ABattlePokemon* Defender);
};
