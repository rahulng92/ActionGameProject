// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystem/Ability/ActionGameEnemyGameplayAbility.h"
#include "Characters/ActionGameEnemyCharacter.h"

AActionGameEnemyCharacter* UActionGameEnemyGameplayAbility::GetEnemyCharacterFromActorInfo()
{
    if (!CachedActionGameEnemyCharacter.IsValid())
    {
        CachedActionGameEnemyCharacter = Cast<AActionGameEnemyCharacter>(CurrentActorInfo->AvatarActor);
    }

    return CachedActionGameEnemyCharacter.IsValid()? CachedActionGameEnemyCharacter.Get() : nullptr;
}

UEnemyCombatComponent* UActionGameEnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo()
{
    AActionGameEnemyCharacter* EnemyCharacter = GetEnemyCharacterFromActorInfo();
    if (EnemyCharacter == nullptr)
    {
        return nullptr;
    }

    return EnemyCharacter->GetEnemyCombatComponent();
}
