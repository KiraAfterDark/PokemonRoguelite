// Copyright Falling Snow Interactive 2023


#include "PokemonInstance.h"

UPokemonInstance::UPokemonInstance() {}

void UPokemonInstance::Init(UPokemonData* D, const int L, const FStatBlock I)
{
	Data = D;
    Level = L;
    Ivs = I;
    
    Stats = FStatBlock(Data->BaseStats, Ivs, Level);
    
    Attacks = Data->Attacks;
    
    // Health = FHealth(Stats.Hp);
}

void UPokemonInstance::Init(const UPokemonInstanceData* InstanceData)
{
	Data = InstanceData->Data;
	Level = InstanceData->Level;
	Ivs = InstanceData->Ivs;
	
	Stats = FStatBlock(Data->BaseStats, Ivs, Level);
	
	Attacks = Data->Attacks;
	
	Health = NewObject<UHealth>();
	Health->Initialize(Stats.Hp);
}

UHealth* UPokemonInstance::GetHealth()
{
	return Health;
}

FStatBlock* UPokemonInstance::GetStats()
{
	return &Stats;
}
