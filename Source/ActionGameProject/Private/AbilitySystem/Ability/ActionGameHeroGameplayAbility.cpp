// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Ability/ActionGameHeroGameplayAbility.h"
#include "Characters/ActionGameHeroCharacter.h"
#include "Controllers/ActionGameHeroController.h"


UActionGameHeroGameplayAbility::UActionGameHeroGameplayAbility()
{
	UE_LOG(LogTemp, Warning, TEXT("created gameplay ability %s"), *this->GetName());
}

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
