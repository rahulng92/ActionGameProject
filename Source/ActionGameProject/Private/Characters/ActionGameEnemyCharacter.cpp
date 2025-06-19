// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ActionGameEnemyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/Combat/EnemyCombatComponent.h"
#include "Engine/AssetManager.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "DebugHelper.h"

AActionGameEnemyCharacter::AActionGameEnemyCharacter()
{
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 180.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1000.f;

	EnemyCombatComponent = CreateDefaultSubobject<UEnemyCombatComponent>("EnemyCombatComponent");
}

UPawnCombatComponent* AActionGameEnemyCharacter::GetPawnCombatComponent() const
{
	return EnemyCombatComponent;
}

void AActionGameEnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitEnemyStartupData();
}

void AActionGameEnemyCharacter::InitEnemyStartupData()
{
	if (CharacterStartUpData.IsNull())
	{
		return;
	}

	// Enginer API to get data assets from project , similar to using something like resource.Load in Unity
	UAssetManager::GetStreamableManager().RequestAsyncLoad(
		CharacterStartUpData.ToSoftObjectPath(),
		FStreamableDelegate::CreateLambda(
			[this]()
			{
				if (UDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.Get())
				{
					LoadedData->GiveToAbilitySystemComponent(CustomAbilitySystemComponent);
					Debug::Print(TEXT("Enemy startup data loaded"));
				}
			}
		)
	);
}
