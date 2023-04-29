// Copyright Falling Snow Interactive 2023


#include "AttackAction.h"

float UAttackAction::GetPriority()
{
    return 1 + (Attacker->GetStats()->Speed / 1000.0f);
}
