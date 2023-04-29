// Copyright Falling Snow Interactive 2023


#include "BattleUi.h"



void UBattleUi::ShowText(FString T)
{
    Text = T;
    DisplayText();
}

void UBattleUi::RequestAction(ABattleTrainer* BattleTrainer)
{
    StartRequestAction(BattleTrainer);
}

void UBattleUi::ActionSelected(UBattleAction* SelectedAction)
{
    BattleActionSelected.Broadcast(SelectedAction);
}


