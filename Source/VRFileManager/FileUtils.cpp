// Fill out your copyright notice in the Description page of Project Settings.


#include "FileUtils.h"
#define DRIVES_BUF_SIZE 512

// Sets default values for this component's properties
UFileUtils::UFileUtils()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

float UFileUtils::CalculateScale(FFileInfo fileInfo, float scale)
{
	return fileInfo.fileSize / scale;
}

TArray<FString> UFileUtils::GetDrives()
{
	TArray<FString> drives;
	TCHAR drivesBuf[DRIVES_BUF_SIZE];

	auto lenght = GetLogicalDriveStrings(DRIVES_BUF_SIZE, drivesBuf);
	
	if (lenght <= 0) {
		UE_LOG(FileSystem, Error, TEXT("%s"), TEXT("No drives detected!"));
	}
	else if (lenght > DRIVES_BUF_SIZE) {
		UE_LOG(FileSystem, Error, TEXT("%s"), TEXT("Allocated drives buffer is too small!"));
	}
	else {
		TCHAR* currentDisk = drivesBuf;

		while (*currentDisk) {
			FString driveLetter;
			driveLetter.AppendChar(*currentDisk);
			driveLetter.Append(":\\");
			drives.Add(driveLetter);

			while (*currentDisk) {
				currentDisk++;
			}

			currentDisk++;
		}
	}

	return drives;
}


// Called when the game starts
void UFileUtils::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFileUtils::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

