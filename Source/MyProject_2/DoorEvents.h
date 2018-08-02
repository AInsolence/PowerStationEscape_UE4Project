// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "DoorEvents.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_2_API UDoorEvents : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorEvents();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	UPROPERTY(VisibleAnywhere)
	bool IsDoorOpen = false;
	UPROPERTY(EditAnywhere)
	ATriggerVolume* DoorInteractionArea = nullptr;
	UPROPERTY(BlueprintAssignable)
	FDoorEvent OpenDoor;
	UPROPERTY(BlueprintAssignable)
	FDoorEvent CloseDoor;

	AActor* Owner = nullptr;
	AActor* Player = nullptr;
};
