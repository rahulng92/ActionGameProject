// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "ActionGameInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONGAMEPROJECT_API UActionGameInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(
		const UDataAsset_InputConfig* InputConfig,
		const FGameplayTag& InputTag,
		ETriggerEvent TriggerEvent,
		UserObject* ContextObject,
		CallbackFunc Func
	);
};

template<class UserObject, typename CallbackFunc>
inline void UActionGameInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InputConfig,const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	//this is just UE's custom Assert
	checkf(InputConfig, TEXT("Input Config data asset is null, cant proceed with binding"));

	if (UInputAction* FoundAction = InputConfig->FindNativeInputActionByTag(InputTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
}
