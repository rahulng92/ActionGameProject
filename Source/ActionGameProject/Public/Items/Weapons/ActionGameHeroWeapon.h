// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/ActionGameWeaponBase.h"
#include "GameplayAbilitySpecHandle.h"
#include "ActionGameTypes/ActionGameStructTypes.h"
#include "ActionGameHeroWeapon.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONGAMEPROJECT_API AActionGameHeroWeapon : public AActionGameWeaponBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
	FActionGameHeroWeaponData HeroWeaponData;

	UFUNCTION(BlueprintCallable)
	void AssignGrantedAbilitySpecHandle(const TArray<FGameplayAbilitySpecHandle> InSpecHandles);

	UFUNCTION(BlueprintPure)
	TArray<FGameplayAbilitySpecHandle> GetGrantedAbilitySpecHandles() const;

private:
	TArray<FGameplayAbilitySpecHandle> GrantedAbilitySpecHandles;
};
