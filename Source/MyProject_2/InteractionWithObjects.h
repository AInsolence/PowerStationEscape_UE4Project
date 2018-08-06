// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Engine/TriggerVolume.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "InteractionWithObjects.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_2_API UInteractionWithObjects : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractionWithObjects();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	bool isInteractNow = false;
private:
	UPROPERTY()
	float PlayerHandsLength = 150.f;
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent * InputComponent = nullptr;
	void SetupInputComponent();
	void FindPhysicsHandleComponent();
	FTwoVectors GetLineTrace() const;
	FHitResult GetFirstHitObject() const;
	void InteractWithObject() const;
	void Grab();
	void Release();
};
