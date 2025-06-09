// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/ActionGameHeroWeapon.h"

void AActionGameHeroWeapon::AssignGrantedAbilitySpecHandle(const TArray<FGameplayAbilitySpecHandle> InSpecHandles)
{
	GrantedAbilitySpecHandles = InSpecHandles;
}

TArray<FGameplayAbilitySpecHandle> AActionGameHeroWeapon::GetGrantedAbilitySpecHandles() const
{
	return GrantedAbilitySpecHandles;
}
