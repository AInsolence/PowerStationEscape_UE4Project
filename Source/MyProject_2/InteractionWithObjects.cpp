// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractionWithObjects.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UInteractionWithObjects::UInteractionWithObjects()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractionWithObjects::BeginPlay()
{
	Super::BeginPlay();
	SetupInputComponent();
}


// Called every frame
void UInteractionWithObjects::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInteractionWithObjects::SetupInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		InputComponent->BindAction("Interaction", IE_Pressed, this, &UInteractionWithObjects::InteractWithDoor);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot find InputComponent owned by %s."), *(GetOwner()->GetName()));
	}
}

void UInteractionWithObjects::InteractWithDoor()
{
	UE_LOG(LogTemp, Warning, TEXT("F key PRESSED"));
	isInteractNow = true;
}

