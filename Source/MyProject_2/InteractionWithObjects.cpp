// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractionWithObjects.h"
#include "Engine/World.h"
#include "Components/PrimitiveComponent.h"
#include "KeyUnlocker.h"
#include "InteractionBehavior.h"
#include "DrawDebugHelpers.h"

#define OUT

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
	FindPhysicsHandleComponent();
	SetupInputComponent();
}


// Called every frame
void UInteractionWithObjects::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	/*DrawDebugPoint(
		GetWorld(),
		GetLineTrace().v2,
		10.0f,
		FColor::Red,
		true,
		1.0f
	);*/
	if (!PhysicsHandle) return;
	/// if the physics handle is attached
	if (PhysicsHandle->GrabbedComponent) {
		/// move the object that we're holding
		PhysicsHandle->SetTargetLocation(GetLineTrace().v2);
	}
}

void UInteractionWithObjects::SetupInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		InputComponent->BindAction("Interaction", IE_Pressed, this, &UInteractionWithObjects::InteractWithObject);
		InputComponent->BindAction("Grab", IE_Pressed, this, &UInteractionWithObjects::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UInteractionWithObjects::Release);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot find InputComponent owned by %s."), *(GetOwner()->GetName()));
	}
}

void UInteractionWithObjects::FindPhysicsHandleComponent()
{
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot find physical handler owned by %s."),
			*(GetOwner()->GetName()));
	}
}

FTwoVectors UInteractionWithObjects::GetLineTrace() const
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);
	FVector LineTraceEnd = PlayerViewPointLocation + 
		PlayerViewPointRotation.Vector()*PlayerHandsLength;
	return FTwoVectors(PlayerViewPointLocation, LineTraceEnd);
}

FHitResult UInteractionWithObjects::GetFirstHitObject() const
{
	FHitResult HitObject;
	GetWorld()->LineTraceSingleByObjectType(
		OUT HitObject,
		GetLineTrace().v1,
		GetLineTrace().v2,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody)
	);
	return HitObject;
}

void UInteractionWithObjects::InteractWithObject()
{
	UE_LOG(LogTemp, Warning, TEXT("Interaction!"));
	if (GetFirstHitObject().GetActor() && GetFirstHitObject().GetActor()->FindComponentByClass<UKeyUnlocker>())
	{
		UE_LOG(LogTemp, Warning, TEXT("Key finded!"));
		GetFirstHitObject().GetActor()->FindComponentByClass<UKeyUnlocker>()->Interact();
	}
	if (GetFirstHitObject().GetActor() && GetFirstHitObject().GetActor()->FindComponentByClass<UInteractionBehavior>())
	{
		UE_LOG(LogTemp, Warning, TEXT("Key finded!"));
		GetFirstHitObject().GetActor()->FindComponentByClass<UInteractionBehavior>()->Interact();
	}
}

void UInteractionWithObjects::Grab()
{
	if (GetFirstHitObject().GetActor() && PhysicsHandle)// if hit an object
	{
		auto MeshComponent = GetFirstHitObject().GetComponent();
		PhysicsHandle->GrabComponent(
			MeshComponent,
			NAME_None,
			MeshComponent->GetOwner()->GetActorLocation(),
			true
		);
	}
}

void UInteractionWithObjects::Release()
{
	if (PhysicsHandle)
	{
		PhysicsHandle->ReleaseComponent();
	}
}
