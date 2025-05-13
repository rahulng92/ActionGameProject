// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UActionGameGameplayAbility;
class UActionGameAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class ACTIONGAMEPROJECT_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UActionGameAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray< TSubclassOf < UActionGameGameplayAbility > > ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray< TSubclassOf < UActionGameGameplayAbility > > ReactiveAbilities;// like death, on hit reactions

	//ApplyLevel is for difficulty adjustment
	void GrantAbilities(const TArray< TSubclassOf < UActionGameGameplayAbility > >& InAbilitiesToGive, UActionGameAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
};
