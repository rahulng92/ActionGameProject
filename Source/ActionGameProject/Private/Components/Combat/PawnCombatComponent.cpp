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

	WeaponToRegister->OnWeaponHitTargetBegin.BindUObject(this, &ThisClass::OnHitTargetActorStart);
	WeaponToRegister->OnWeaponHitTargetEnd.BindUObject(this, &ThisClass::OnHitTargetActorEnd);
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
			// every hit actor that was part of the collision event is removed
			OverlappedActors.Empty();
		}
	}

	return nullptr;
}

void UPawnCombatComponent::OnHitTargetActorStart(AActor* HitActor)
{
}

void UPawnCombatComponent::OnHitTargetActorEnd(AActor* InteractedActor)
{
}
