// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Ability/ActionGameGameplayAbility.h"
#include "ActionGameHeroGameplayAbility.generated.h"

class AActionGameHeroCharacter;
class AActionGameHeroController;
class UHeroCombatComponent;
class UCharacterMovementComponent;

/**
 * 
 */
UCLASS()
class ACTIONGAMEPROJECT_API UActionGameHeroGameplayAbility : public UActionGameGameplayAbility
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintPure, Category = "Hero|Ability")
	AActionGameHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Hero|Ability")
	AActionGameHeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Hero|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Hero|Ability")
	UCharacterMovementComponent* GetHeroMovementComponentFromActorInfo();

	// Notes:applying a gameplay effect is how we will actually affect character attributes
	UFUNCTION(BlueprintPure, Category = "Hero|Ability")
	FGameplayEffectSpecHandle MakeHeroDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass,float WeaponBaseDamage, FGameplayTag CurrentAttackTypeTag, int32 UsedComboCount);

private:

	TWeakObjectPtr<AActionGameHeroCharacter> CachedHeroCharacter;
	TWeakObjectPtr<AActionGameHeroController> CachedHeroController;
};
