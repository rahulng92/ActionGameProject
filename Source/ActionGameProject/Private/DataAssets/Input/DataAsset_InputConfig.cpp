// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/Input/DataAsset_InputConfig.h"

UInputAction* UDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& Tag) const
{
    for (const FActionGameInputActionConfig& InputActionConfig : NativeInputActions)
    {
        if (InputActionConfig.InputTag == Tag && InputActionConfig.InputAction != nullptr)
        {
            return InputActionConfig.InputAction;
        }
    }

    return nullptr;
}
