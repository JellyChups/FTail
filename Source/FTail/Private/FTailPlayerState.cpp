// Fill out your copyright notice in the Description page of Project Settings.


#include "FTailPlayerState.h"
#include "FTailAbilitySystemComponent.h"
#include "FTailAttributeSet.h"

AFTailPlayerState::AFTailPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UFTailAbilitySystemComponent>("AbilitySystemComponent");

	AttributeSet = CreateDefaultSubobject<UFTailAttributeSet>("AttributeSet");

}

UAbilitySystemComponent* AFTailPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
