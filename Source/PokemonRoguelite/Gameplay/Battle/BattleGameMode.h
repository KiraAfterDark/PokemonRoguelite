// Copyright Falling Snow Interactive 2023

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "BattlePokemon.h"
#include "BattleTrainers/BattleTrainer.h"
#include "GameFramework/GameModeBase.h"
#include "Ui/BattleUi.h"
#include "BattleGameMode.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogPhase, Display, All);
DECLARE_LOG_CATEGORY_EXTERN(LogPhaseIntro, Display, All);
DECLARE_LOG_CATEGORY_EXTERN(LogPhasePrepare, Display, All);
DECLARE_LOG_CATEGORY_EXTERN(LogPhaseResolve, Display, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBattleActionSelectedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUsePokemonDelegate);

/**
 * 
 */
UCLASS()
class POKEMONROGUELITE_API ABattleGameMode final : public AGameModeBase
{
	GENERATED_BODY()

// Variables
public:
	UPROPERTY(EditDefaultsOnly, Category="Player Trainer")
	TSubclassOf<ABattleTrainer> PlayerTrainerController;
	
	UPROPERTY(EditDefaultsOnly, Category="Player Trainer")
	UTrainerData* PlayerTrainerData;

	UPROPERTY(BlueprintReadOnly, Category="Player Trainer")
	ABattleTrainer* PlayerTrainer;

	UPROPERTY(EditDefaultsOnly, Category="Enemy Trainer")
	TSubclassOf<ABattleTrainer> EnemyTrainerController;

	UPROPERTY(EditDefaultsOnly,Category="Enemy Trainer")
	UTrainerData* EnemyTrainerData;

	UPROPERTY(BlueprintReadOnly, Category="Enemy Trainer")
	ABattleTrainer* EnemyTrainer;

	UPROPERTY(EditDefaultsOnly, Category="Pokemon")
	TSubclassOf<ABattlePokemon> BattlePokemonSource;
	
	UPROPERTY(EditDefaultsOnly, Category="Containers")
	USceneComponent* SceneRoot;
	
	UPROPERTY(EditDefaultsOnly, Category="Containers")
	USceneComponent* PlayerContainer;

	UPROPERTY(EditDefaultsOnly, Category="Containers")
	USceneComponent* EnemyContainer;
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UBattleUi> BattleUiWidget;

	UPROPERTY()
	UBattleUi* BattleUi;

	UPROPERTY(BlueprintReadOnly, Category="Player Trainer")
	UTrainerInstance* PlayerTrainerInstance;

	UPROPERTY(BlueprintReadOnly, Category="Enemy Trainer")
	UTrainerInstance* EnemyTrainerInstance;
	
private:
	FTimerHandle DelayTimerHandle;
	FOnUsePokemonDelegate OnUsePokemonDelegate;

	UPROPERTY()
	TArray<UBattleAction*> BattleActions;
	bool PlayerActionReady = false;
	bool EnemyActionReady = false;

	UPROPERTY()
	TArray<UBattleAction*> RemainingActions;

// Functions
public:
	ABattleGameMode();
protected:
	virtual void BeginPlay() override;
private:
	ABattleTrainer* SetupTrainer(UTrainerInstance* Instance, TSubclassOf<ABattleTrainer> Controller, USceneComponent* Container, ABattleTrainer* OpponentTrainer) const;

	void DelayFunction(FTimerDelegate::TMethodPtr<ABattleGameMode> Callback, float Time, bool Loop);

	// General Methods

	// 1. Intro Phase
	void StartIntroPhase();
	void EnemyIntro();

	UFUNCTION()
	void FinishEnemyIntro(ABattlePokemon* Pokemon);
	void PlayerIntro();

	UFUNCTION()
	void FinishPlayerIntro(ABattlePokemon* Pokemon);
	void FinishIntroPhase();

	// 2. Prepare Phase
	void StartPreparePhase();

	UFUNCTION()
	void PlayerActionSelected(UBattleAction* BattleAction);

	UFUNCTION()
	void EnemyActionSelected(UBattleAction* BattleAction);
	void CheckActions();
	void FinishPreparePhase();

	// 3. Resolve Phase
	void StartResolvePhase();
	TArray<UBattleAction*> SortBattleActions(TArray<UBattleAction*> BattleActions);
	void ResolveNextAction();
	void ResolveAction(UBattleAction* BattleAction);

	UFUNCTION()
	void ActionResolved(UBattleAction* BattleAction);
	void EvaluateField();
	void FinishResolveActions();

	// Actions
	// Attack Action
	void PerformAttack(UAttackData Attack, ABattlePokemon* Attacker, ABattlePokemon* Defender);
};
