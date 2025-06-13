// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Ability/ActionGameGameplayAbility.h"
#include "ActionGameHeroGameplayAbility.generated.h"

class AActionGameHeroCharacter;
class AActionGameHeroController;
class UHeroCombatComponent;

/**
 * 
 */
UCLASS()
class ACTIONGAMEPROJECT_API UActionGameHeroGameplayAbility : public UActionGameGameplayAbility
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AActionGameHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AActionGameHeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();
private:

	TWeakObjectPtr<AActionGameHeroCharacter> CachedHeroCharacter;
	TWeakObjectPtr<AActionGameHeroController> CachedHeroController;
};
