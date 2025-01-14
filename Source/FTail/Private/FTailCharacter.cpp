// Fill out your copyright notice in the Description page of Project Settings.


#include "FTailCharacter.h"
#include "FTailPlayerState.h"
#include "AbilitySystemComponent.h"

AFTailCharacter::AFTailCharacter()
{

}

void AFTailCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilityActorInfo();

}

/*void AFTailCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilityActorInfo();

}
*/

void AFTailCharacter::InitAbilityActorInfo()
{
	AFTailPlayerState* FTailPlayerState = GetPlayerState<AFTailPlayerState>();
	check(FTailPlayerState);
	FTailPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(FTailPlayerState, this);
	AbilitySystemComponent = FTailPlayerState->GetAbilitySystemComponent();
	AttributeSet = FTailPlayerState->GetAttributeSet();
}
