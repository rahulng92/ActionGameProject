// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ActionGameBaseCharacter.h"
#include "AbilitySystem/ActionGameAbilitySystemComponent.h"
#include "AbilitySystem/ActionGameAttributeSet.h"

// Sets default values
AActionGameBaseCharacter::AActionGameBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	// This is cause some decals are affecting the ground and we dont want those to affect the character
	GetMesh()->bReceivesDecals = false;

	CustomAbilitySystemComponent = CreateDefaultSubobject<UActionGameAbilitySystemComponent>(TEXT("CustomAbilitySystem"));
	CustomAttributeSetComponent = CreateDefaultSubobject<UActionGameAttributeSet>(TEXT("CustomAttributeSet"));

}

UAbilitySystemComponent* AActionGameBaseCharacter::GetAbilitySystemComponent() const
{
	return GetCustomAbilitySystemComponent();
}

void AActionGameBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (CustomAbilitySystemComponent != nullptr)
	{
		CustomAbilitySystemComponent->InitAbilityActorInfo(this, this);

		ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("No startup data assigned for character %s"), *GetName());
	}
}

