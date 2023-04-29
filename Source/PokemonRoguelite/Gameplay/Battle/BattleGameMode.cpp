// Copyright Falling Snow Interactive 2023


#include "BattleGameMode.h"

#include "BattleActions/AttackAction.h"

DEFINE_LOG_CATEGORY(LogPhase);
DEFINE_LOG_CATEGORY(LogPhaseIntro);
DEFINE_LOG_CATEGORY(LogPhasePrepare);
DEFINE_LOG_CATEGORY(LogPhaseResolve);

ABattleGameMode::ABattleGameMode()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SceneRoot->SetupAttachment(RootComponent);

	PlayerContainer = CreateDefaultSubobject<USceneComponent>(TEXT("PlayerContainer"));
	PlayerContainer->AttachToComponent(SceneRoot, FAttachmentTransformRules::KeepRelativeTransform);

	EnemyContainer = CreateDefaultSubobject<USceneComponent>(TEXT("EnemyContainer"));
	EnemyContainer->AttachToComponent(SceneRoot, FAttachmentTransformRules::KeepRelativeTransform);
}

void ABattleGameMode::BeginPlay()
{
	Super::BeginPlay();

	BattleUi = CreateWidget<UBattleUi>(GetWorld(), BattleUiWidget, "Battle Ui");
	BattleUi->AddToViewport();

	PlayerTrainerInstance = NewObject<UTrainerInstance>();
	PlayerTrainerInstance->Init(PlayerTrainerData);
	
	EnemyTrainerInstance = NewObject<UTrainerInstance>(EnemyTrainerData);
	EnemyTrainerInstance->Init(EnemyTrainerData);
	
	PlayerTrainer = SetupTrainer(PlayerTrainerInstance, PlayerTrainerController, PlayerContainer, EnemyTrainer);
	EnemyTrainer = SetupTrainer(EnemyTrainerInstance, EnemyTrainerController, EnemyContainer, PlayerTrainer);

	DelayFunction(&ABattleGameMode::StartIntroPhase, 1.0f, false);
}

ABattleTrainer* ABattleGameMode::SetupTrainer(UTrainerInstance* Instance, const TSubclassOf<ABattleTrainer> Controller, USceneComponent* Container, ABattleTrainer* OpponentTrainer) const
{
	if(Instance == nullptr || Container == nullptr)
	{
		return nullptr;
	}
	
	ABattleTrainer* Trainer = static_cast<ABattleTrainer*>(GetWorld()->SpawnActor(Controller));
	Trainer -> AttachToComponent(Container, FAttachmentTransformRules::SnapToTargetIncludingScale);

	ABattlePokemon* BattlePokemon = static_cast<ABattlePokemon*>(GetWorld()->SpawnActor(BattlePokemonSource));

	Trainer->Initialize(Instance, BattlePokemon, OpponentTrainer, BattleUi);

	return Trainer;
}

void ABattleGameMode::DelayFunction(const FTimerDelegate::TMethodPtr<ABattleGameMode> Callback, const float Time, const bool Loop)
{
	GetWorld()->GetTimerManager().SetTimer(DelayTimerHandle, this, Callback, Time, Loop);
}

#pragma region 1. Intro Phase

void ABattleGameMode::StartIntroPhase()
{
	UE_LOG(LogPhase, Display, TEXT("Start Phase: Intro"))
	
	EnemyIntro();
}

void ABattleGameMode::EnemyIntro()
{
	UE_LOG(LogPhaseIntro, Display, TEXT("Enemy Start Intro"))
	EnemyTrainer->TrainerUsePokemon.AddDynamic(this, &ABattleGameMode::FinishEnemyIntro);
	EnemyTrainer->UsePokemon();
}

void ABattleGameMode::FinishEnemyIntro(ABattlePokemon* Pokemon)
{
	UE_LOG(LogPhaseIntro, Display, TEXT("Enemy Finish Intro"))
	EnemyTrainer->TrainerUsePokemon.RemoveDynamic(this, &ABattleGameMode::FinishEnemyIntro);
	DelayFunction(&ABattleGameMode::PlayerIntro, 1.0f, false);
}

void ABattleGameMode::PlayerIntro()
{
	UE_LOG(LogPhaseIntro, Display, TEXT("Player Start Intro"))
	PlayerTrainer->TrainerUsePokemon.AddDynamic(this, &ABattleGameMode::FinishPlayerIntro);
	PlayerTrainer->UsePokemon();
}

void ABattleGameMode::FinishPlayerIntro(ABattlePokemon* Pokemon)
{
	UE_LOG(LogPhaseIntro, Display, TEXT("Player Finish Intro"))
	PlayerTrainer->TrainerUsePokemon.RemoveDynamic(this, &ABattleGameMode::FinishPlayerIntro);
	DelayFunction(&ABattleGameMode::FinishIntroPhase, 1.0f, false);
}

void ABattleGameMode::FinishIntroPhase()
{
	UE_LOG(LogPhase, Display, TEXT("End Phase: Intro"))
	DelayFunction(&ABattleGameMode::StartPreparePhase, 1.0f, false);
}

#pragma endregion 

#pragma region 2. Prepare Phase

void ABattleGameMode::StartPreparePhase()
{
	UE_LOG(LogPhase, Display, TEXT("Start Phase: Prepare"))
	
	PlayerActionReady = false;
	EnemyActionReady = false;

	PlayerTrainer->TrainerActionSelected.AddDynamic(this, &ABattleGameMode::PlayerActionSelected);
	PlayerTrainer->RequestAction();
	
	EnemyTrainer->TrainerActionSelected.AddDynamic(this, &ABattleGameMode::EnemyActionSelected);
	EnemyTrainer->RequestAction();
}

void ABattleGameMode::PlayerActionSelected(FBattleAction BattleAction)
{
	UE_LOG(LogPhasePrepare, Display, TEXT("Player Action Selected"))
	PlayerTrainer->TrainerActionSelected.RemoveDynamic(this, &ABattleGameMode::PlayerActionSelected);
	PlayerActionReady = true;
	BattleActions.Add(BattleAction);

	CheckActions();
}

void ABattleGameMode::EnemyActionSelected(FBattleAction BattleAction)
{
	UE_LOG(LogPhasePrepare, Display, TEXT("Enemy Action Selected"))
	
	EnemyTrainer->TrainerActionSelected.RemoveDynamic(this, &ABattleGameMode::EnemyActionSelected);
	EnemyActionReady = true;
	BattleActions.Add(BattleAction);

	CheckActions();
}

void ABattleGameMode::CheckActions()
{
	if(!PlayerActionReady || !EnemyActionReady)
	{
		return;
	}

	UE_LOG(LogPhasePrepare, Display, TEXT("All Actions Ready"))
	FinishPreparePhase();
}

void ABattleGameMode::FinishPreparePhase()
{
	UE_LOG(LogPhase, Display, TEXT("Finish Phase: Prepare"))

	StartResolvePhase();
}

#pragma endregion 

#pragma region 3. Resolve Phase

void ABattleGameMode::StartResolvePhase()
{
	UE_LOG(LogPhase, Display, TEXT("Start Phase: Resolve"));
	RemainingActions = SortBattleActions(BattleActions);

	DelayFunction(&ABattleGameMode::ResolveNextAction, 1.0f, false);
}

TArray<FBattleAction> ABattleGameMode::SortBattleActions(TArray<FBattleAction> BAs)
{
	// TODO - Actually do some sorting, will need to implement priority on the BattleActions
	UE_LOG(LogPhaseResolve, Display, TEXT("Sorting Actions - Needs to be sorted"));
	TArray<UBattleAction*> Sorted = TArray<FBattleAction>(BAs);
	return Sorted;
}

void ABattleGameMode::ResolveNextAction()
{
	UE_LOG(LogPhaseResolve, Display, TEXT("Resolve next action"));
	
	if(RemainingActions.IsEmpty())
	{
		UE_LOG(LogPhaseResolve, Display, TEXT("No more actions"));
		FinishResolveActions();
	}
	
	UBattleAction* NextAction = RemainingActions.Pop();
	ResolveAction(NextAction);
}

void ABattleGameMode::ResolveAction(UBattleAction* BattleAction)
{
	UE_LOG(LogPhaseResolve, Display, TEXT("Resolve Action"));

	const auto* AttackAction = dynamic_cast<FAttackAction*>(BattleAction);
	if(AttackAction != nullptr)
	{
		PerformAttack(AttackAction);
	}
	else
	{
		UE_LOG(LogPhaseResolve, Display, TEXT("This battle action was never initialized."));
	}
}

void ABattleGameMode::ActionResolved(UBattleAction* BattleAction)
{
	UE_LOG(LogPhaseResolve, Display, TEXT("Action Resolved"));
}

void ABattleGameMode::EvaluateField()
{
	UE_LOG(LogPhaseResolve, Display, TEXT("Evaluate Field"));
}

void ABattleGameMode::FinishResolveActions()
{
	UE_LOG(LogPhaseResolve, Display, TEXT("Finish Phase: Resolve"));
}

#pragma region Attack Action

void ABattleGameMode::PerformAttack(const FAttackAction* AttackAction)
{
	
}

#pragma endregion 

#pragma endregion 
