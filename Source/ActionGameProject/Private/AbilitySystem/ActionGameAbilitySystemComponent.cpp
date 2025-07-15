// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ActionGameAbilitySystemComponent.h"
#include "AbilitySystem/Ability/ActionGameGameplayAbility.h"
#include "AbilitySystem/Ability/ActionGameHeroGameplayAbility.h"

void UActionGameAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid())
	{
		return;
	}

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;

		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UActionGameAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{

	if (!InInputTag.IsValid())
	{
		return;
	}

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;

		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UActionGameAbilitySystemComponent::GrantHeroWeaponAbilities(const TArray<FActionGameHeroAbilitySet>& InDefaultWeaponAblities, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandle)
{
	if (InDefaultWeaponAblities.IsEmpty())
	{
		return;
	}

	for (const FActionGameHeroAbilitySet& AbilitySet : InDefaultWeaponAblities)
	{
		if (!AbilitySet.isValid()) continue;
		
		
		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		OutGrantedAbilitySpecHandle.AddUnique(GiveAbility(AbilitySpec));
	}
}

void UActionGameAbilitySystemComponent::RemoveGrantedHeroWeaponAbilites(UPARAM(ref)TArray<FGameplayAbilitySpecHandle>& AbilitySpecHandlesToRemove)
{
	if (AbilitySpecHandlesToRemove.IsEmpty())
	{
		return;
	}

	for (const FGameplayAbilitySpecHandle& handle : AbilitySpecHandlesToRemove)
	{
		if (handle.IsValid())
		{
			ClearAbility(handle);
		}
	}

	AbilitySpecHandlesToRemove.Empty();
}

