// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interfaces/PawnCombatInterface.h"
#include "Interfaces/PawnUIInterface.h"
#include "ActionGameBaseCharacter.generated.h"


class UActionGameAbilitySystemComponent;
class UActionGameAttributeSet;
class UDataAsset_StartUpDataBase;
class UPawnUIComponent;
class UHeroUIComponent;
class UEnemyUIComponent;

UCLASS()
class ACTIONGAMEPROJECT_API AActionGameBaseCharacter : public ACharacter, public IAbilitySystemInterface, public IPawnCombatInterface, public IPawnUIInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AActionGameBaseCharacter();

	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface Interface

	//~ Begin IPawnCombatInterface Interface.
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ Begin IPawnCombatInterface Interface.

	//~ Begin IPawnUIInterface Interface.
	virtual UPawnUIComponent* GetPawnUIComponent() const override;

	virtual UHeroUIComponent* GetHeroUIComponent() const override;

	virtual UEnemyUIComponent* GetEnemyUIComponent() const override;
	//~ End IPawnUIInterface Interface

protected:

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UActionGameAbilitySystemComponent* CustomAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UActionGameAttributeSet* CustomAttributeSetComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AbilitySystem")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;

public:

	FORCEINLINE UActionGameAbilitySystemComponent* GetCustomAbilitySystemComponent() const { return CustomAbilitySystemComponent; }
	
	FORCEINLINE	UActionGameAttributeSet* GetCustomAttributeSetComponent() const { return CustomAttributeSetComponent; }
};
