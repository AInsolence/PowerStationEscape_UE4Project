// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractionBehavior.h"


// Sets default values for this component's properties
UInteractionBehavior::UInteractionBehavior()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UInteractionBehavior::Interact()
{
	UE_LOG(LogTemp, Error, TEXT("From InteractionBehavior.h: need to override this function in the child class"));
}

// Called when the game starts
void UInteractionBehavior::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractionBehavior::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

