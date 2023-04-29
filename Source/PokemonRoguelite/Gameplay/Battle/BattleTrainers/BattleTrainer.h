// Copyright Falling Snow Interactive 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperSpriteComponent.h"
#include "PokemonRoguelite/Gameplay/PokemonInstance.h"
#include "PokemonRoguelite/Gameplay/TrainerInstance.h"
#include "PokemonRoguelite/Gameplay/Battle/BattlePokemon.h"
#include "PokemonRoguelite/Gameplay/Battle/Ui/BattleUi.h"
#include "BattleTrainer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTrainerUsePokemon, ABattlePokemon*, BattlePokemon);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTrainerActionSelected, UBattleAction*, BattleAction);

UCLASS()
class POKEMONROGUELITE_API ABattleTrainer : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	UTrainerInstance* Instance;

	UPROPERTY(EditDefaultsOnly, Category="Visuals")
	UPaperSpriteComponent* PaperSprite;
	
	UPROPERTY(EditDefaultsOnly, Category="Containers")
	USceneComponent* SceneRoot;

	UPROPERTY(EditDefaultsOnly, Category="Containers")
	USceneComponent* PokemonContainer;

	UPROPERTY(BlueprintReadOnly)
	TArray<UPokemonInstance*> Party;

	UPROPERTY(BlueprintReadOnly)
	ABattlePokemon* Pokemon;

	UPROPERTY()
	FTrainerUsePokemon TrainerUsePokemon;

	UPROPERTY()
	FTrainerActionSelected TrainerActionSelected;

protected:
	UPROPERTY()
	UBattleUi* BattleUi;
	
private:	
	FTimerHandle DelayTimerHandle;

	TFunction<void()> UsePokemonCallback;

	UPROPERTY()
	ABattleTrainer* EnemyTrainer;
	
public:	
	ABattleTrainer();
	void Initialize(UTrainerInstance* TrainerInstance, ABattlePokemon* BattlePokemon, ABattleTrainer* EnemyBattleTrainer, UBattleUi* BattleUi);

	virtual void UsePokemon();
	void FinishUsePokemon();

	void virtual RequestAction();
	
protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void ActionSelected(UBattleAction* SelectedAction);
};
