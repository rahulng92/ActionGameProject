// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class AActionGameWeaponBase;

UENUM(BlueprintType)
enum class EToggleDamageType : uint8
{
	CurrentEquipedWeapon,
	LeftHand,
	RightHand
};

/**
 * 
 */
UCLASS()
class ACTIONGAMEPROJECT_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "ActionGame|Combat")
	void RegisterSpawnedWeapon(FGameplayTag WeaponTagToRegister, AActionGameWeaponBase* WeaponToRegister, bool bRegsiterAsEquipped = false);

	UFUNCTION(BlueprintCallable, Category = "ActionGame|Combat")
	AActionGameWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag WeaponTagToGet) const;

	UPROPERTY(BlueprintReadWrite, Category = "ActionGame|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category = "ActionGame|Combat")
	AActionGameWeaponBase* GetCharacterCurrentEquippedWeapon() const;

	UFUNCTION(BlueprintCallable, Category = "ActionGame|Combat")
	AActionGameWeaponBase* ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType = EToggleDamageType::CurrentEquipedWeapon);
private:
	TMap<FGameplayTag, AActionGameWeaponBase*> CharacterCarriedWeaponMap;
};
