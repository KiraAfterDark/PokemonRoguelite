// Copyright Falling Snow Interactive 2023


#include "PokemonInstance.h"

UPokemonInstance::UPokemonInstance() {}

void UPokemonInstance::Initialize(UPokemonData* D, const int L, const FStatBlock I)
{
	Data = D;
    Level = L;
    Ivs = I;
    
    Stats = FStatBlock(Data->BaseStats, Ivs, Level);

	for (auto Attack : Data->Attacks)
	{
		Attacks.Add(Attack);
	}
	
	Health = NewObject<UHealth>();
	Health->Initialize(Stats.Hp);

	Name = D->Name;
}

void UPokemonInstance::Initialize(const UPokemonInstanceData* InstanceData)
{
	Initialize(InstanceData->Data, InstanceData->Level, InstanceData->Ivs);
}

UHealth* UPokemonInstance::GetHealth()
{
	return Health;
}

FStatBlock* UPokemonInstance::GetStats()
{
	return &Stats;
}
