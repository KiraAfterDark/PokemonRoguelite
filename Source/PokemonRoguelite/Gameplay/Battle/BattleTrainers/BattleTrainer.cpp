// Copyright Falling Snow Interactive 2023


#include "BattleTrainer.h"

#include "PokemonRoguelite/Gameplay/TrainerInstance.h"

ABattleTrainer::ABattleTrainer()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SceneRoot->SetupAttachment(RootComponent);

	PaperSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSprite"));
	PaperSprite -> SetupAttachment(SceneRoot);

	PokemonContainer = CreateDefaultSubobject<USceneComponent>(TEXT("PokemonContainer"));
	PokemonContainer -> SetupAttachment(SceneRoot);
}

void ABattleTrainer::BeginPlay()
{
}

void ABattleTrainer::Initialize(UTrainerInstance* TrainerInstance, ABattlePokemon* BattlePokemon)
{
	Instance = TrainerInstance;
	Pokemon = BattlePokemon;

	PaperSprite->SetSprite(Instance->GetBattleSprite());

	Party = Instance->GetParty();

	Pokemon->AttachToComponent(PokemonContainer, FAttachmentTransformRules::SnapToTargetIncludingScale);
}

void ABattleTrainer::UsePokemon()
{
	Pokemon->Initialize(Party[0]);
}


