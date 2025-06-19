// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionGameFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/ActionGameAbilitySystemComponent.h"
#include "Interfaces/PawnCombatInterface.h"

UActionGameAbilitySystemComponent* UActionGameFunctionLibrary::NativeGetWarriorASCFromActor(AActor* InActor)
{
	check(InActor);

	return CastChecked<UActionGameAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UActionGameFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	check(InActor);
	
	UActionGameAbilitySystemComponent* AbilitySystemComponent = NativeGetWarriorASCFromActor(InActor);
	if (!AbilitySystemComponent->HasMatchingGameplayTag(TagToAdd))
	{
		AbilitySystemComponent->AddLooseGameplayTag(TagToAdd);
	}
}

void UActionGameFunctionLibrary::RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
	check(InActor);

	UActionGameAbilitySystemComponent* AbilitySystemComponent = NativeGetWarriorASCFromActor(InActor);

	if (AbilitySystemComponent->HasMatchingGameplayTag(TagToRemove))
	{
		AbilitySystemComponent->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool UActionGameFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	check(InActor);

	UActionGameAbilitySystemComponent* AbilitySystemComponent = NativeGetWarriorASCFromActor(InActor);
	
	return AbilitySystemComponent->HasMatchingGameplayTag(TagToCheck);
}

void UActionGameFunctionLibrary::BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EActionGameConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoesActorHaveTag(InActor, TagToCheck) ? EActionGameConfirmType::Yes : EActionGameConfirmType::No;
}

UPawnCombatComponent* UActionGameFunctionLibrary::NativeGetPawnCombatComponentFromActor(AActor* InActor)
{
	check(InActor);

	if (IPawnCombatInterface* PawnCombatInterface = Cast<IPawnCombatInterface>(InActor))
	{
		return PawnCombatInterface->GetPawnCombatComponent();
	}

	return nullptr;
}

UPawnCombatComponent* UActionGameFunctionLibrary::BP_GetPawnCombatComponentFromActor(AActor* InActor, EActionGameValidType& OutValidType)
{
	UPawnCombatComponent* CombatComponent = NativeGetPawnCombatComponentFromActor(InActor);
	
	OutValidType = CombatComponent ? EActionGameValidType::Valid : EActionGameValidType::Invalid;

	return CombatComponent;
}
