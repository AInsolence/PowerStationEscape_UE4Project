// Fill out your copyright notice in the Description page of Project Settings.

#include "ButtonInteractionbehavior.h"

void UButtonInteractionbehavior::Interact()
{
	UE_LOG(LogTemp, Warning, TEXT("BUTTON BEHAVIOR WORK WELL!"));
	PushButton.Broadcast();
}
