// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Ability/ActionGameGameplayAbility.h"
#include "AbilitySystem/ActionGameAbilitySystemComponent.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

#include "DebugHelper.h"

void UActionGameGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);
	if (AbilityActivationPolicy == EActionGameAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo != nullptr && !Spec.IsActive())
		{
			const FString handle = FString::Printf(TEXT("Owner Actor: %s"), *ActorInfo->OwnerActor->GetActorLabel());
			if (!ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle))
			{
				Debug::Print(TEXT("Could not activate ability ") + handle, FColor::Red);
			}
		}
	}
}

void UActionGameGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (AbilityActivationPolicy == EActionGameAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo)
		{
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}
}

UPawnCombatComponent* UActionGameGameplayAbility::GetPawnCombatComponentFromActorInfo() const
{
	return GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombatComponent>();
}

// note that CurrentActorInfo si the actor that has been granted an abity so its basically a way to access the actor from the Ability Instance
UActionGameAbilitySystemComponent* UActionGameGameplayAbility::GetActionGameAbilitySystemComponentFromActorInfo() const
{
	return Cast<UActionGameAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}

FActiveGameplayEffectHandle UActionGameGameplayAbility::NativeApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& SpecHandle)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);

	check(TargetASC && SpecHandle.IsValid());

	return GetActionGameAbilitySystemComponentFromActorInfo()->ApplyGameplayEffectSpecToTarget(
		*SpecHandle.Data,
		TargetASC
	);
}

FActiveGameplayEffectHandle UActionGameGameplayAbility::BP_ApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& SpecHandle, EActionGameSuccessType& OutSuccessType)
{
	FActiveGameplayEffectHandle ActiveGameplayEffectHandle = NativeApplyEffectSpecHandleToTarget(TargetActor, SpecHandle);

	OutSuccessType = ActiveGameplayEffectHandle.WasSuccessfullyApplied() ? EActionGameSuccessType::Successful : EActionGameSuccessType::Failed;

	return ActiveGameplayEffectHandle;
}
