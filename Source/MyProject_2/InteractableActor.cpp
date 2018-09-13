// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractableActor.h"
#include "InteractionBehavior.h"


// Sets default values
AInteractableActor::AInteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AInteractableActor::SetInteractionBehaviorComponent(UInteractionBehavior * NewInteractionBehavior)
{
	InteractionBehavior = NewInteractionBehavior;
}

void AInteractableActor::Interact()
{
	if (InteractionBehavior)
	{
		InteractionBehavior->Interact();
	}
}

// Called when the game starts or when spawned
void AInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

