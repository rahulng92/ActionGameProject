// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/ActionGameBaseAnimInstance.h"
#include "HeroLinkedAnimeLayer.generated.h"

class UActionGameHeroAnimInstance;

/**
 * 
 */
UCLASS()
class ACTIONGAMEPROJECT_API UHeroLinkedAnimeLayer : public UActionGameBaseAnimInstance
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	UActionGameHeroAnimInstance* GetHeroAnimInstance() const;
};
