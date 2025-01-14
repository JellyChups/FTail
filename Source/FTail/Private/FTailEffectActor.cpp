// Fill out your copyright notice in the Description page of Project Settings.


#include "FTailEffectActor.h"
#include "AbilitySystemInterface.h"
#include "FTailAttributeSet.h"
#include "Components/SphereComponent.h"

AFTailEffectActor::AFTailEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(Mesh);
	
}

void AFTailEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UFTailAttributeSet* FTailAttributeSet = Cast<UFTailAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UFTailAttributeSet::StaticClass()));
		UFTailAttributeSet* MutableFTailAttributeSet = const_cast<UFTailAttributeSet*>(FTailAttributeSet);
		MutableFTailAttributeSet->SetHealth(FTailAttributeSet->GetHealth() + 25.f);
		Destroy();

	}
}

void AFTailEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}


void AFTailEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AFTailEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AFTailEffectActor::EndOverlap);
	
}



