// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActionGameWidgetBase.generated.h"


class UHeroUIComponent;
class UEnemyUIComponent;
/**
 * 
 */
UCLASS()
class ACTIONGAMEPROJECT_API UActionGameWidgetBase : public UUserWidget
{
	GENERATED_BODY()


protected:
	virtual void NativeOnInitialized() override;

	//BlueprintImplementableEvent means we can assign this in BP and we do not need o define it in this base class
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Owning Hero UI Component Initialized"))
	void BP_OnOwningHeroUIComponentInitialized(UHeroUIComponent* OwningHeroUIComponent);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Owning Enemy UI Component Initialized"))
	void BP_OnOwningEnemyUIComponentInitialized(UEnemyUIComponent* UEnemyUIComponent);

public:
	
	UFUNCTION(BlueprintCallable)
	void InitEnemyCreatedWidget(AActor* OwningEnemyActor);
};
