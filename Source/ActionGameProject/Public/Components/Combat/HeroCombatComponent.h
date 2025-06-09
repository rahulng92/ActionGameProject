// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "HeroCombatComponent.generated.h"

class AActionGameHeroWeapon;
/**
 * 
 */
UCLASS()
class ACTIONGAMEPROJECT_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "ActionGame|Combat")
	AActionGameHeroWeapon* GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const;
};
