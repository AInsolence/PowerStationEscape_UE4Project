// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "Sound/SoundCue.h"
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
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Status)
	FRotator InitRotation;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = IsOpen)
	bool IsOpen = false;

private:
	UPROPERTY(EditAnywhere)
	AActor* Locker = nullptr;
	UPROPERTY(EditAnywhere)
	ATriggerVolume* DoorInteractionArea = nullptr;
	UPROPERTY(BlueprintAssignable)
	FDoorEvent OpenDoor;
	UPROPERTY(BlueprintAssignable)
	FDoorEvent CloseDoor;
	UPROPERTY(BlueprintAssignable)
	FDoorEvent AccessDenied;

	AActor* Owner = nullptr;
	AActor* Player = nullptr;
};
