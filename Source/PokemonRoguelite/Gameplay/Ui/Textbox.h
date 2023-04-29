// Copyright Falling Snow Interactive 2023

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Textbox.generated.h"

/**
 * 
 */
UCLASS()
class POKEMONROGUELITE_API UTextbox : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite)
	FString Text;

public:
	UFUNCTION(BlueprintCallable)
	void SetText(FString T);
	
};
