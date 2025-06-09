// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class AActionGameWeaponBase;
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

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AActionGameWeaponBase* GetCharacterCurrentEquippedWeapon() const;
private:
	TMap<FGameplayTag, AActionGameWeaponBase*> CharacterCarriedWeaponMap;
	
};
