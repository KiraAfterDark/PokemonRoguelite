// Copyright Falling Snow Interactive 2023


#include "BattleGameMode.h"

ABattleGameMode::ABattleGameMode()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SceneRoot->SetupAttachment(RootComponent);

	PlayerContainer = CreateDefaultSubobject<USceneComponent>(TEXT("PlayerContainer"));
	PlayerContainer->AttachToComponent(SceneRoot, FAttachmentTransformRules::KeepRelativeTransform);

	PlayerPokemonContainer = CreateDefaultSubobject<USceneComponent>(TEXT("PlayerPokemonContainer"));
	PlayerPokemonContainer->AttachToComponent(PlayerContainer, FAttachmentTransformRules::KeepRelativeTransform);

	EnemyContainer = CreateDefaultSubobject<USceneComponent>(TEXT("EnemyContainer"));
	EnemyContainer->AttachToComponent(SceneRoot, FAttachmentTransformRules::KeepRelativeTransform);

	EnemyPokemonContainer = CreateDefaultSubobject<USceneComponent>(TEXT("EnemyPokemonContainer"));
	EnemyPokemonContainer->AttachToComponent(EnemyContainer, FAttachmentTransformRules::KeepRelativeTransform);
}

void ABattleGameMode::BeginPlay()
{
	Super::BeginPlay();

	BattleUi = CreateWidget<UUserWidget>(GetWorld(), BattleUiWidget, "Battle Ui");

	PlayerTrainerInstance = NewObject<UTrainerInstance>();
	PlayerTrainerInstance->Init(PlayerTrainerData);
	
	EnemyTrainerInstance = NewObject<UTrainerInstance>(EnemyTrainerData);
	EnemyTrainerInstance->Init(EnemyTrainerData);
	
	PlayerTrainer = SetupTrainer(PlayerTrainerInstance, PlayerTrainerController, PlayerContainer);
	EnemyTrainer = SetupTrainer(EnemyTrainerInstance, EnemyTrainerController, EnemyContainer);
}

ABattleTrainer* ABattleGameMode::SetupTrainer(UTrainerInstance* Instance, const TSubclassOf<ABattleTrainer> Controller, USceneComponent* Container) const
{
	if(Instance == nullptr || Container == nullptr)
	{
		return nullptr;
	}
	
	ABattleTrainer* Trainer = static_cast<ABattleTrainer*>(GetWorld()->SpawnActor(Controller));
	Trainer -> AttachToComponent(Container, FAttachmentTransformRules::SnapToTargetIncludingScale);

	ABattlePokemon* BattlePokemon = static_cast<ABattlePokemon*>(GetWorld()->SpawnActor(BattlePokemonSource));

	Trainer->Initialize(Instance, BattlePokemon);

	return Trainer;
}
