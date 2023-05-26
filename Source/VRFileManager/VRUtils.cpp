// Fill out your copyright notice in the Description page of Project Settings.


#include "VRUtils.h"

USceneComponent* UVRUtils::controllerR = nullptr;
USceneComponent* UVRUtils::controllerL = nullptr;

// Sets default values for this component's properties
UVRUtils::UVRUtils()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

USceneComponent* UVRUtils::GetRightController()
{
	return controllerR;
}

USceneComponent* UVRUtils::GetLeftController()
{
	return controllerL;
}

void UVRUtils::SetRightController(USceneComponent* controller)
{
	controllerR = controller;
}

void UVRUtils::SetLeftController(USceneComponent* controller)
{
	controllerL = controller;
}

// Called when the game starts
void UVRUtils::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UVRUtils::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

