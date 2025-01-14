// Fill out your copyright notice in the Description page of Project Settings.


#include "FTailCharacterBase.h"
#include "FTailAbilitySystemComponent.h"
#include "FTailAttributeSet.h"

AFTailCharacterBase::AFTailCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UFTailAbilitySystemComponent>("AbilitySystemComponent");

	AttributeSet = CreateDefaultSubobject<UFTailAttributeSet>("AttributeSet");

}

UAbilitySystemComponent* AFTailCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AFTailCharacterBase::BeginPlay()
{
	Super::BeginPlay();

}



