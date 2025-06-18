// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/ActionGameBaseCharacter.h"
#include "ActionGameEnemyCharacter.generated.h"

class UEnemyCombatComponent;
class UDataAsset_EnemyStartUpData;
/**
 * 
 */
UCLASS()
class ACTIONGAMEPROJECT_API AActionGameEnemyCharacter : public AActionGameBaseCharacter
{
	GENERATED_BODY()

public:

	AActionGameEnemyCharacter();

protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	UEnemyCombatComponent* EnemyCombatComponent;

private:
	void InitEnemyStartupData();

public:
	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; }
};
