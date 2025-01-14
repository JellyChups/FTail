// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FTailCharacterBase.h"
#include "FTailCharacter.generated.h"

/**
 * 
 */
UCLASS()
class FTAIL_API AFTailCharacter : public AFTailCharacterBase
{
	GENERATED_BODY()
	
public:
	AFTailCharacter();

	virtual void PossessedBy(AController* NewController) override;
	//virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();

};
