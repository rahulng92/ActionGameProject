// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/ActionGameHeroController.h"

AActionGameHeroController::AActionGameHeroController()
{
	HeroTeamId = FGenericTeamId(0);
}

FGenericTeamId AActionGameHeroController::GetGenericTeamId() const
{
	return HeroTeamId;
}
