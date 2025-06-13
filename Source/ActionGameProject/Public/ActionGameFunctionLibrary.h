// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ActionGameFunctionLibrary.generated.h"

class UActionGameAbilitySystemComponent;

UENUM()
enum class UActionGameConfirmType : uint8
{
	Yes,
	No
};

/**
 * 
 */
UCLASS()
class ACTIONGAMEPROJECT_API UActionGameFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	static UActionGameAbilitySystemComponent* NativeGetWarriorASCFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "ActionGame|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category = "ActionGame|FunctionLibrary")
	static void RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove);

	static bool NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck);

	//ExpandEnumAsExecs provdes multiple execution pins for use on blueprint callable functions
	UFUNCTION(BlueprintCallable, Category = "ActionGame|FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, UActionGameConfirmType& OutConfirmType);
};
