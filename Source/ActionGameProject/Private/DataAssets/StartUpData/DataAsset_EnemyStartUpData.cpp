// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_EnemyStartUpData.h"
#include "AbilitySystem/Ability/ActionGameEnemyGameplayAbility.h"
#include "AbilitySystem/ActionGameAbilitySystemComponent.h"

void UDataAsset_EnemyStartUpData::GiveToAbilitySystemComponent(UActionGameAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	if (EnemyCombatAbilites.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy Startup Combat Abilities is empty"));
		return;
	}

	for (const TSubclassOf<UActionGameEnemyGameplayAbility>& AbilityClass : EnemyCombatAbilites)
	{
		if (!AbilityClass) continue;

		FGameplayAbilitySpec AbilitySpec(AbilityClass);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InASCToGive->GiveAbility(AbilitySpec);
	}
}
