// Copyright Falling Snow Interactive 2023

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Health.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHealthChangeDelegate);

/**
 * 
 */
UCLASS()
class POKEMONROGUELITE_API UHealth : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable)
    FHealthChangeDelegate OnHealthChange;

    UPROPERTY(BlueprintAssignable)
    FHealthChangeDelegate OnHealthZero;

private:
    int CurrentHealth;
    int MaxHealth;

public:
    void Initialize(int Hp);

    UFUNCTION(BlueprintCallable, Category="Health")
    int GetCurrentHealth();

    UFUNCTION(BlueprintCallable, Category="Health")
    int GetMaxHealth();

    UFUNCTION(BlueprintCallable, Category="Health")
    float GetNormalized();

    void Heal(int Amount);
    void Damage(int Amount);
};
