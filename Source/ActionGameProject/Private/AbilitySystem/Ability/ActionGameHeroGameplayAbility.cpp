// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Ability/ActionGameHeroGameplayAbility.h"
#include "Characters/ActionGameHeroCharacter.h"
#include "AbilitySystem/ActionGameAbilitySystemComponent.h"
#include "Controllers/ActionGameHeroController.h"
#include "ActionGameProjectGameplayTags.h"


AActionGameHeroCharacter* UActionGameHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedHeroCharacter.IsValid())
	{
		CachedHeroCharacter = Cast<AActionGameHeroCharacter>(CurrentActorInfo->AvatarActor);
	}

	return CachedHeroCharacter.IsValid()? CachedHeroCharacter.Get() : nullptr;
}

AActionGameHeroController* UActionGameHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedHeroController.IsValid())
	{
		CachedHeroController = Cast<AActionGameHeroController>(CurrentActorInfo->PlayerController);
	}

	return CachedHeroController.IsValid() ? CachedHeroController.Get() : nullptr;
}

UHeroCombatComponent* UActionGameHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}

UCharacterMovementComponent * UActionGameHeroGameplayAbility::GetHeroMovementComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetCharacterMovement();
}

FGameplayEffectSpecHandle UActionGameHeroGameplayAbility::MakeHeroDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, float WeaponBaseDamage, FGameplayTag CurrentAttackTypeTag, int32 UsedComboCount)
{
	check(EffectClass);

	FGameplayEffectContextHandle ContextHandle = GetActionGameAbilitySystemComponentFromActorInfo()->MakeEffectContext();

	ContextHandle.SetAbility(this);
	ContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
	ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(), GetAvatarActorFromActorInfo());

	FGameplayEffectSpecHandle Handle = GetActionGameAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(
		EffectClass,
		GetAbilityLevel(),
		ContextHandle
	);

	Handle.Data->SetSetByCallerMagnitude(
		ActionGameProjectGameplayTags::Shared_SetByCaller_BaseDamage,
		WeaponBaseDamage
	);

	if (CurrentAttackTypeTag.IsValid())
	{
		Handle.Data->SetSetByCallerMagnitude(CurrentAttackTypeTag, UsedComboCount);
	}

	return Handle;
}
