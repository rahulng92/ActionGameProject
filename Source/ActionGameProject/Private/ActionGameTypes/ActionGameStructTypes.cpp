// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionGameTypes/ActionGameStructTypes.h"
#include "AbilitySystem/Ability/ActionGameGameplayAbility.h"

bool FActionGameHeroAbilitySet::isValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
