// Copyright Falling Snow Interactive 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperSpriteComponent.h"
#include "PokemonRoguelite/Gameplay/PokemonInstance.h"
#include "PokemonRoguelite/Gameplay/TrainerInstance.h"
#include "PokemonRoguelite/Gameplay/Battle/BattlePokemon.h"
#include "BattleTrainer.generated.h"

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

protected:
private:
	
public:	
	ABattleTrainer();
	void Initialize(UTrainerInstance* TrainerInstance, ABattlePokemon* BattlePokemon);

	void UsePokemon();
	
protected:
	virtual void BeginPlay() override;

private:	
	

};
