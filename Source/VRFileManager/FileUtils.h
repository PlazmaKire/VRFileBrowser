// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FileBrowser/Browser.h"
#include "CoreMinimal.h"
#include "Windows/MinWindows.h"
#include "Components/ActorComponent.h"
#include "FileUtils.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VRFILEMANAGER_API UFileUtils : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFileUtils();

	UFUNCTION(BlueprintCallable, Category = "FileSystem")
		float CalculateScale(FFileInfo fileInfo, float scale);

	UFUNCTION(BlueprintCallable, Category = "FileSystem")
		TArray<FString> GetDrives();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
