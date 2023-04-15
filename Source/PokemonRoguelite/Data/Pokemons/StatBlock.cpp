// Copyright Falling Snow Interactive 2023


#include "StatBlock.h"

FStatBlock::FStatBlock(): Hp(0)
                        , Attack(0)
                        , Defense(0)
                        , SpecialAttack(0)
                        , SpecialDefense(0)
                        , Speed(0) {}

FStatBlock::FStatBlock(int H, int A, int D, int Sa, int Sd, int S)
{
	Hp = H;
	Attack = A;
	Defense = D;
	SpecialAttack = Sa;
	SpecialDefense = Sd;
	Speed = S;
}

FStatBlock::FStatBlock(FStatBlock BaseStats, FStatBlock Ivs, int Level)
{
	Hp = CalculateHp(BaseStats.Hp, Ivs.Hp, Level);
	Attack = CalculateStat(BaseStats.Attack, Ivs.Attack, Level);
	Defense = CalculateStat(BaseStats.Defense, Ivs.Defense, Level);
	SpecialAttack = CalculateStat(BaseStats.SpecialAttack, Ivs.SpecialAttack, Level);
	SpecialDefense = CalculateStat(BaseStats.SpecialDefense, Ivs.SpecialDefense, Level);
	Speed = CalculateStat(BaseStats.Speed, Ivs.Speed, Level);
}

FStatBlock FStatBlock::GenerateIvs()
{
	return FStatBlock(FMath::RandRange(1, 31),
		FMath::RandRange(1, 31),
		FMath::RandRange(1, 31),
		FMath::RandRange(1, 31),
		FMath::RandRange(1, 31),
		FMath::RandRange(1, 31));
}

int FStatBlock::CalculateHp(int Base, int Iv, int Level)
{
	float Stat = 0.01f * (2 * Base + Iv) * Level;
	Stat = FMath::Floor(Stat);
	Stat += Level + 10;
	return Stat;
	
}

int FStatBlock::CalculateStat(const int Base, const int Iv, const int Level /*, int Nature*/)
{
	float Stat = 0.01f * (2 * Base + Iv) * Level;
	Stat += 5;
	const int Floored = FMath::Floor(Stat);
	return Floored; // * Nature
}
