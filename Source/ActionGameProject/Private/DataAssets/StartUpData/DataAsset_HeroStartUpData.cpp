// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_HeroStartUpData.h"
#include "AbilitySystem/Ability/ActionGameGameplayAbility.h"
#include "AbilitySystem/ActionGameAbilitySystemComponent.h"


void UDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(UActionGameAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	for (const FActionGameHeroAbilitySet AbilitySet : HeroStartUpAbilitySets)
	{
		if (!AbilitySet.isValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		InASCToGive->GiveAbility(AbilitySpec);
	}
}
