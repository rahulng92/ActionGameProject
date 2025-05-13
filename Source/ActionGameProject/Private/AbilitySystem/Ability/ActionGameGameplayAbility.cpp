// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Ability/ActionGameGameplayAbility.h"
#include "AbilitySystem/ActionGameAbilitySystemComponent.h"

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
