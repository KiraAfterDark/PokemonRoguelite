// Copyright Falling Snow Interactive 2023


#include "TrainerInstance.h"

#include "PokemonRoguelite/Data/TrainerData.h"

UTrainerInstance::UTrainerInstance() {}

void UTrainerInstance::Init(UTrainerData* D)
{
    Data = D;

    for (const auto PokemonInstanceData : Data->PartyData)
    {
        UPokemonInstance* Instance = NewObject<UPokemonInstance>();
        Instance->Initialize(PokemonInstanceData);
        Party.Add(Instance);
    }
}

UPaperSprite* UTrainerInstance::GetBattleSprite() const
{
    return Data->FrontSprite;
}

TArray<UPokemonInstance*> UTrainerInstance::GetParty()
{
    return Party;
}

FName UTrainerInstance::GetName()
{
    return Data->Name;
}
