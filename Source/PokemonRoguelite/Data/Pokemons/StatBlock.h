// Copyright Falling Snow Interactive 2023

#pragma once

#include "CoreMinimal.h"
#include "StatBlock.generated.h"

/**
 * 
 */
USTRUCT()
struct FStatBlock
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Stats")
	int Hp;

	UPROPERTY(EditDefaultsOnly, Category="Stats")
	int Attack;

	UPROPERTY(EditDefaultsOnly, Category="Stats")
	int Defense;

	UPROPERTY(EditDefaultsOnly, Category="Stats")
	int SpecialAttack;

	UPROPERTY(EditDefaultsOnly, Category="Stats")
	int SpecialDefense;

	UPROPERTY(EditDefaultsOnly, Category="Stats")
	int Speed;

public:
	FStatBlock();
	FStatBlock(int H, int A, int D, int Sa, int Sd, int S);
	FStatBlock(FStatBlock BaseStats, FStatBlock Ivs, int Level);

	static FStatBlock GenerateIvs();
	
	static int CalculateHp(int Base, int Iv, int Level);
	static int CalculateStat(int Base, int Iv, int Level);
};
