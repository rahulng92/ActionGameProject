// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ActionGameTypes/ActionGameEnumTypes.h"
#include "ActionGameGameplayAbility.generated.h"

class UPawnCombatComponent;
class UActionGameAbilitySystemComponent;

UENUM(BlueprintType)
enum class EActionGameAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};


UCLASS()
class ACTIONGAMEPROJECT_API UActionGameGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	//~ Begin UGameplayAbility Interface.
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		bool bReplicateEndAbility,
		bool bWasCancelled
	) override;
	//~ End UGameplayAbility Interface

	UPROPERTY(EditDefaultsOnly, Category = "ActionGameGameplayAbility")
	EActionGameAbilityActivationPolicy AbilityActivationPolicy = EActionGameAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category = "ActionGame|Ability")
	UPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category = "ActionGame|Ability")
	UActionGameAbilitySystemComponent* GetActionGameAbilitySystemComponentFromActorInfo() const;

	FActiveGameplayEffectHandle NativeApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& SpecHandle);

	UFUNCTION(BlueprintCallable, Category = "ActionGame|Ability", meta = (DisplayName = "Apply Gameplay Effect Spec Handle To Target Actor", ExpandEnumAsExecs = "OutSuccessType"))
	FActiveGameplayEffectHandle BP_ApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& SpecHandle, EActionGameSuccessType& OutSuccessType);
};
