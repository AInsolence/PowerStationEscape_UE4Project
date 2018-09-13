// Fill out your copyright notice in the Description page of Project Settings.

#include "KeyInteractionBehavior.h"


// Sets default values for this component's properties
UKeyInteractionBehavior::UKeyInteractionBehavior()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UKeyInteractionBehavior::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UKeyInteractionBehavior::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

