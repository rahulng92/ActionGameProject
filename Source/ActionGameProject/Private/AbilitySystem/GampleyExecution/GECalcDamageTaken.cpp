// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GampleyExecution/GECalcDamageTaken.h"
#include "AbilitySystem/ActionGameAttributeSet.h"
#include "ActionGameProjectGameplayTags.h"
#include "DebugHelper.h"

struct FActionGameDamageCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageTaken)

	FActionGameDamageCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UActionGameAttributeSet, AttackPower, Source, false) // get the attack power of the source
		DEFINE_ATTRIBUTE_CAPTUREDEF(UActionGameAttributeSet, DefensePower, Target, false) // get the defence power of the target
		DEFINE_ATTRIBUTE_CAPTUREDEF(UActionGameAttributeSet, DamageTaken, Target, false) // get the defence power of the target
	}
};

static const FActionGameDamageCapture& GetActionGameDamageCapture()
{
	static FActionGameDamageCapture ActionGameDamageCapture;
	return ActionGameDamageCapture;
}

UGECalcDamageTaken::UGECalcDamageTaken()
{
	RelevantAttributesToCapture.Add(GetActionGameDamageCapture().AttackPowerDef);
	RelevantAttributesToCapture.Add(GetActionGameDamageCapture().DefensePowerDef);
	RelevantAttributesToCapture.Add(GetActionGameDamageCapture().DamageTakenDef);
}

void UGECalcDamageTaken::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& EffectSpec = ExecutionParams.GetOwningSpec();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = EffectSpec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = EffectSpec.CapturedTargetTags.GetAggregatedTags();

	float SourceAttackPower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetActionGameDamageCapture().AttackPowerDef, EvaluateParameters, SourceAttackPower);

	float BaseDamage = 0.f;
	int32 UsedLightAttackComboCount = 0;
	int32 UsedHeavyAttackComboCount = 0;

	//Debug::Print(TEXT("SourceAttackPower"), SourceAttackPower);

	for (const TPair<FGameplayTag, float>& TagMagnitude : EffectSpec.SetByCallerTagMagnitudes)
	{
		if (TagMagnitude.Key.MatchesTagExact(ActionGameProjectGameplayTags::Shared_SetByCaller_BaseDamage))
		{
			BaseDamage = TagMagnitude.Value;
			//Debug::Print(TEXT("BaseDamage"), BaseDamage);
		}

		if (TagMagnitude.Key.MatchesTagExact(ActionGameProjectGameplayTags::Player_SetByCaller_AttackType_Light))
		{
			UsedLightAttackComboCount = TagMagnitude.Value;
			//Debug::Print(TEXT("Light attack combo count"), UsedLightAttackComboCount);
		}

		if (TagMagnitude.Key.MatchesTagExact(ActionGameProjectGameplayTags::Player_SetByCaller_AttackType_Heavy))
		{
			UsedHeavyAttackComboCount = TagMagnitude.Value;
			//Debug::Print(TEXT("heavy attack combo count"), UsedHeavyAttackComboCount);
		}
	}

	float TargetDefensePower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetActionGameDamageCapture().DefensePowerDef, EvaluateParameters, TargetDefensePower);
	//Debug::Print(TEXT("TargetDefensePower"), TargetDefensePower);

	if (UsedLightAttackComboCount != 0)
	{
		const float DamageIncreasePercentLight = (UsedLightAttackComboCount - 1) * 0.05 + 1.f;

		BaseDamage *= DamageIncreasePercentLight;
		//Debug::Print(TEXT("ScaledBaseDamageLight"),BaseDamage);
	}

	if (UsedHeavyAttackComboCount != 0)
	{
		const float DamageIncreasePercentHeavy = UsedHeavyAttackComboCount * 0.15f + 1.f;

		BaseDamage *= DamageIncreasePercentHeavy;
		//Debug::Print(TEXT("ScaledBaseDamageHeavy"),BaseDamage);
	}

	const float FinalDamageDone = BaseDamage * SourceAttackPower / TargetDefensePower;
	//Debug::Print(TEXT("FinalDamageDone"), FinalDamageDone);

	if (FinalDamageDone > 0.f)
	{
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(
				GetActionGameDamageCapture().DamageTakenProperty,
				EGameplayModOp::Override,
				FinalDamageDone
			)
		);
	}
}
