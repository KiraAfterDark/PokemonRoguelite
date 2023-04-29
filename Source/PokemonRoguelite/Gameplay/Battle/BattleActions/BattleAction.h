// Copyright Falling Snow Interactive 2023

#pragma once

#include "CoreMinimal.h"
#include "BattleAction.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogBattleAction, Display, All);

/**
 * 
 */
UCLASS(BlueprintType)
class POKEMONROGUELITE_API UBattleAction : public UObject
{
    GENERATED_BODY()

public:
    virtual float GetPriority();

    TEnumAsByte<EBattleActionType> GetActionType();
};

UENUM()
enum EBattleActionType
{
    None,
    Attack,
};
