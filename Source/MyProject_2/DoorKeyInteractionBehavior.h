// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionBehavior.h"
#include "DoorKeyInteractionBehavior.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYPROJECT_2_API UDoorKeyInteractionBehavior : public UInteractionBehavior
{
	GENERATED_BODY()

	void Interact() override final;
	
	
};
