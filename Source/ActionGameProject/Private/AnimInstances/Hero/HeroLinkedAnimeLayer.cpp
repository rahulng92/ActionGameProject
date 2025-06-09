// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Hero/HeroLinkedAnimeLayer.h"
#include "AnimInstances/ActionGameHeroAnimInstance.h"

UActionGameHeroAnimInstance* UHeroLinkedAnimeLayer::GetHeroAnimInstance() const
{
    return Cast<UActionGameHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
