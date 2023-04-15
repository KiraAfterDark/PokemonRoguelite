// Copyright Falling Snow Interactive 2023


#include "Health.h"

void UHealth::Initialize(int Hp)
{
    CurrentHealth = Hp;
    MaxHealth = Hp;
}

int UHealth::GetCurrentHealth()
{
    return CurrentHealth;
}

int UHealth::GetMaxHealth()
{
    return MaxHealth;
}

float UHealth::GetNormalized()
{
    return static_cast<float>(CurrentHealth)/static_cast<float>(MaxHealth);
}

void UHealth::Heal(int Amount)
{
    CurrentHealth += Amount;
    CurrentHealth = FMath::Clamp(CurrentHealth, 0, MaxHealth);

    OnHealthChange.Broadcast();
}

void UHealth::Damage(int Amount)
{
    CurrentHealth -= Amount;
    CurrentHealth = FMath::Clamp(CurrentHealth, 0, MaxHealth);

    OnHealthChange.Broadcast();

    if(CurrentHealth <= 0)
    {
        OnHealthZero.Broadcast();
    }
}
