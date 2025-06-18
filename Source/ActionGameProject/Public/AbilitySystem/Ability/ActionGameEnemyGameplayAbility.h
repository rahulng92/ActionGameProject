// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Ability/ActionGameGameplayAbility.h"
#include "ActionGameEnemyGameplayAbility.generated.h"

class AActionGameEnemyCharacter;
class UEnemyCombatComponent;
/**
 * 
 */
UCLASS()
class ACTIONGAMEPROJECT_API UActionGameEnemyGameplayAbility : public UActionGameGameplayAbility
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category = "ActionGame|Ability")
	AActionGameEnemyCharacter* GetEnemyCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "ActionGame|Ability")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AActionGameEnemyCharacter> CachedActionGameEnemyCharacter;
};
