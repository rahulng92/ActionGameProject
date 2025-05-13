// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/ActionGameHeroAnimInstance.h"
#include "Characters/ActionGameHeroCharacter.h"

void UActionGameHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AActionGameHeroCharacter>(OwningCharacter);
	}
}

void UActionGameHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (bHasAcceleration)
	{
		IdleElapsedTime = 0.0f;
		bShouldEnterRelaxedState = false;
	}
	else
	{
		IdleElapsedTime += DeltaSeconds;
		bShouldEnterRelaxedState = (IdleElapsedTime >= EnterRelaxedStateThreshold);
	}
}
