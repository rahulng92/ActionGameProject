// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "ActionGameTypes/ActionGameStructTypes.h"
#include "ActionGameAbilitySystemComponent.generated.h"

UCLASS()
class ACTIONGAMEPROJECT_API UActionGameAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);
	
	UFUNCTION(BlueprintCallable, Category = "ActionGame|Ability", meta = (ApplyLevel = "1"))
	void GrantHeroWeaponAbilities(const TArray<FActionGameHeroAbilitySet>& InDefaultWeaponAblities, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandle);

	UFUNCTION(BlueprintCallable, Category = "ActionGame|Ability")
	void RemoveGrantedHeroWeaponAbilites(UPARAM(ref) TArray<FGameplayAbilitySpecHandle>& AbilitySpecHandlesToRemove);
};
