// Copyright Falling Snow Interactive 2023

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "BattlePokemon.h"
#include "BattleTrainers/BattleTrainer.h"
#include "GameFramework/GameModeBase.h"
#include "BattleGameMode.generated.h"

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
	USceneComponent* PlayerPokemonContainer;

	UPROPERTY(EditDefaultsOnly, Category="Containers")
	USceneComponent* EnemyContainer;

	UPROPERTY(EditDefaultsOnly, Category="Containers")
	USceneComponent* EnemyPokemonContainer;
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> BattleUiWidget;

	UPROPERTY()
	UUserWidget* BattleUi;

	UPROPERTY(BlueprintReadOnly, Category="Player Trainer")
	UTrainerInstance* PlayerTrainerInstance;

	UPROPERTY(BlueprintReadOnly, Category="Enemy Trainer")
	UTrainerInstance* EnemyTrainerInstance;
	
private:

// Functions
public:
	ABattleGameMode();
protected:
	virtual void BeginPlay() override;
private:
	ABattleTrainer* SetupTrainer(UTrainerInstance* Instance, TSubclassOf<ABattleTrainer> Controller, USceneComponent* Container) const;
	
};
