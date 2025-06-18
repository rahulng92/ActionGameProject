// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ActionGameBaseCharacter.h"
#include "AbilitySystem/ActionGameAbilitySystemComponent.h"
#include "AbilitySystem/ActionGameAttributeSet.h"

/** We initialize some basic components that are required for all the Characters ( enemies, player ) that we would need
	We are extending the Gameplay Ability System Component to add some custom behavior for when start building out the player and enemy characters 
*/
AActionGameBaseCharacter::AActionGameBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	// This is cause some decals are affecting the ground and we dont want those to affect the character
	GetMesh()->bReceivesDecals = false;

	CustomAbilitySystemComponent = CreateDefaultSubobject<UActionGameAbilitySystemComponent>(TEXT("CustomAbilitySystem"));
	CustomAttributeSetComponent = CreateDefaultSubobject<UActionGameAttributeSet>(TEXT("CustomAttributeSet"));

}

/** Implementing the Interface IAbilitySystemInterface to return our custom ability system 
*/
UAbilitySystemComponent* AActionGameBaseCharacter::GetAbilitySystemComponent() const
{
	return GetCustomAbilitySystemComponent();
}


/*Called when this Pawn is possessed*/
void AActionGameBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (CustomAbilitySystemComponent != nullptr)
	{
		CustomAbilitySystemComponent->InitAbilityActorInfo(this, this);

		ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("No startup data assigned for character %s"), *GetName());
	}
}

