// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "VRUtils.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VRFILEMANAGER_API UVRUtils : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UVRUtils();

	UFUNCTION(BlueprintCallable, Category = "VR")
		USceneComponent* GetRightController();

	UFUNCTION(BlueprintCallable, Category = "VR")
		USceneComponent* GetLeftController();

	UFUNCTION(BlueprintCallable, Category = "VR")
		void SetRightController(USceneComponent* controller);

	UFUNCTION(BlueprintCallable, Category = "VR")
		void SetLeftController(USceneComponent* controller);

private:
	static USceneComponent* controllerR;
	static USceneComponent* controllerL;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
