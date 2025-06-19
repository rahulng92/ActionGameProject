// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/PawnCombatComponent.h"
#include "Items/Weapons/ActionGameWeaponBase.h"
#include "Components/BoxComponent.h"

#include "DebugHelper.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag WeaponTagToRegister, AActionGameWeaponBase* WeaponToRegister, bool bRegisterAsEquipped)
{
	checkf(!CharacterCarriedWeaponMap.Contains(WeaponTagToRegister), 
		TEXT("A named named %s has already been added as carried weapon"), *WeaponTagToRegister.ToString());
	check(WeaponToRegister);
	CharacterCarriedWeaponMap.Emplace(WeaponTagToRegister, WeaponToRegister);

	if (bRegisterAsEquipped)
	{
		CurrentEquippedWeaponTag = WeaponTagToRegister;
	}
	/*const FString WeaponString = FString::Printf(TEXT("A weapon named: %s has been registered using the tag %s"), *WeaponToRegister->GetName(), *WeaponTagToRegister.ToString());
	
	Debug::Print(WeaponString);*/
}

AActionGameWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag WeaponTagToGet) const
{
	if (CharacterCarriedWeaponMap.Contains(WeaponTagToGet))
	{
		if (AActionGameWeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(WeaponTagToGet))
		{
			return *FoundWeapon;
		}
	}
	return nullptr;
}

AActionGameWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid())
	{
		return nullptr;
	}
	
	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}

AActionGameWeaponBase* UPawnCombatComponent::ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType)
{
	if (ToggleDamageType == EToggleDamageType::CurrentEquipedWeapon)
	{
		AActionGameWeaponBase* WeaponToToggle = GetCharacterCurrentEquippedWeapon();

		check(WeaponToToggle)

		if (bShouldEnable)
		{
			WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		}
		else
		{
			WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
	}

	return nullptr;
}
