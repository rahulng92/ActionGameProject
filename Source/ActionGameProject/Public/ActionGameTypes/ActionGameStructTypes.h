// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayTagContainer.h"
#include "ActionGameStructTypes.generated.h"

class UActionGameGameplayAbility;

USTRUCT(BlueprintType)
struct FActionGameHeroAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UActionGameGameplayAbility> AbilityToGrant;

	bool isValid() const;
};

class UHeroLinkedAnimeLayer;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FActionGameHeroWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UHeroLinkedAnimeLayer> WeaponAnimLayerToLink;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* WeaponInputMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FActionGameHeroAbilitySet> DefaultWeaponAbilities;
};
