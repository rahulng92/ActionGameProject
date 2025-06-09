// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/HeroCombatComponent.h"
#include "Items/Weapons/ActionGameHeroWeapon.h"

AActionGameHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
    return Cast<AActionGameHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}
