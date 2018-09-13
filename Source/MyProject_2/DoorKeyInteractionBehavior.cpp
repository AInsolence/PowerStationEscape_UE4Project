// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorKeyInteractionBehavior.h"

void UDoorKeyInteractionBehavior::Interact()
{
	UE_LOG(LogTemp, Warning, TEXT("NEW key BEHAVIOR WORK WELL!"));
	GetOwner()->Destroy();
}
