// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/ActionGameBaseAnimInstance.h"
#include "ActionGameFunctionLibrary.h"

bool UActionGameBaseAnimInstance::DoesOwnerHaveTag(FGameplayTag TagToCheck) const
{
    if (APawn* OwningPawn = TryGetPawnOwner())
    {
        return UActionGameFunctionLibrary::NativeDoesActorHaveTag(OwningPawn, TagToCheck);
    }

    return false;
}
