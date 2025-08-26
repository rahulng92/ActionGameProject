// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GenericTeamAgentInterface.h"
#include "ActionGameHeroController.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONGAMEPROJECT_API AActionGameHeroController : public APlayerController, public IGenericTeamAgentInterface
{
	GENERATED_BODY()
	
public:

	AActionGameHeroController();

	//~ Begin IGenericTeamAgentInterface
	virtual FGenericTeamId GetGenericTeamId() const override;
	//~ End IGenericTeamAgentInterface

private:
	FGenericTeamId HeroTeamId;
};
