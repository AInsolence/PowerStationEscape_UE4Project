// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionBehavior.h"
#include "ButtonInteractionbehavior.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FButtonEvent);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYPROJECT_2_API UButtonInteractionbehavior : public UInteractionBehavior
{
	GENERATED_BODY()
	
	void Interact() override final;
	UPROPERTY(BlueprintAssignable)
	FButtonEvent PushButton;
	
};
