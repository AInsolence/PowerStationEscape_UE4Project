// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorEvents.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UDoorEvents::UDoorEvents()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorEvents::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	Player = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!DoorInteractionArea)
	{
		UE_LOG(LogTemp, Error, TEXT("DoorInteractionArea does not exist or attached."));
	}
	if (!Player)
	{
		UE_LOG(LogTemp, Error, TEXT("Player does not exist or attached."));
	}
	if (DoorInteractionArea->IsOverlappingActor(Owner)) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Checking true"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Checking false"));
	}
}


// Called every frame
void UDoorEvents::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if(GetWorld()->GetFirstPlayerController()->IsInputKeyDown(EKeys::F))
	{
		if(DoorInteractionArea != nullptr && DoorInteractionArea->IsOverlappingActor(Player))
		{
			UE_LOG(LogTemp, Error, TEXT("Overlap"));
			if (!IsDoorOpen)
			{
				OpenDoor.Broadcast();
			}
			else
			{
				CloseDoor.Broadcast();
			}
		}
	}
}

