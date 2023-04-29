// Copyright Falling Snow Interactive 2023


#include "BattleTrainer.h"

#include "PokemonRoguelite/Gameplay/TrainerInstance.h"
#include "PokemonRoguelite/Gameplay/Battle/BattleActions/AttackAction.h"

ABattleTrainer::ABattleTrainer()
{
	PrimaryActorTick.bCanEverTick = true;

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

void ABattleTrainer::Initialize(UTrainerInstance* TrainerInstance, ABattlePokemon* BattlePokemon, ABattleTrainer* EnemyBattleTrainer, UBattleUi* Ui)
{
	BattleUi = Ui;
	Instance = TrainerInstance;
	Pokemon = BattlePokemon;

	PaperSprite->SetSprite(Instance->GetBattleSprite());

	Party = Instance->GetParty();

	Pokemon->AttachToComponent(PokemonContainer, FAttachmentTransformRules::SnapToTargetIncludingScale);

	EnemyTrainer = EnemyBattleTrainer;
}

void ABattleTrainer::UsePokemon()
{
	Pokemon->Initialize(Party[0]);

	const FString TrainerName = Instance->GetName().ToString();
	const FString PokemonName = Pokemon->GetName().ToString();
	const FString Text = FString::Printf(TEXT("%s uses %s."), *TrainerName, *PokemonName);
	BattleUi->ShowText(Text);
	GetWorld()->GetTimerManager().SetTimer(DelayTimerHandle, this, &ABattleTrainer::FinishUsePokemon, 1.0f, false);
}

void ABattleTrainer::FinishUsePokemon()
{
	BattleUi->HideText();
	if(TrainerUsePokemon.IsBound())
	{
		TrainerUsePokemon.Broadcast(Pokemon);
	}
}

void ABattleTrainer::RequestAction()
{
	UAttackAction* AttackAction = NewObject<UAttackAction>();
	AttackAction->Initialize(Pokemon->GetAttacks()->Top(), Pokemon, EnemyTrainer->Pokemon);
	ActionSelected(AttackAction);
}

void ABattleTrainer::ActionSelected(UBattleAction* SelectedAction)
{
	TrainerActionSelected.Broadcast(SelectedAction);
}




