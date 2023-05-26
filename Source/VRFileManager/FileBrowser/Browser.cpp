// Fill out your copyright notice in the Description page of Project Settings.


#include "Browser.h"
#include <string>
#include <filesystem>
namespace fs = std::filesystem;

DEFINE_LOG_CATEGORY(FileSystem);

// Sets default values for this component's properties
UBrowser::UBrowser()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	startPath = "C:/";
	// ...
}


// Called when the game starts
void UBrowser::BeginPlay()
{
	Super::BeginPlay();

	// ...
	currentPath = fs::path(std::string(TCHAR_TO_UTF8(*startPath)));
	currentDepth = 0;
}


// Called every frame
void UBrowser::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TArray<FFileInfo> UBrowser::GetCurrectDirFiles()
{
	TArray<FFileInfo> contents;

	try {
		for (const auto& entry : fs::directory_iterator(currentPath))
		{
			FFileInfo fileInfo;
			fileInfo.fullPath = FString(entry.path().c_str());
			fileInfo.isDirectory = entry.is_directory();
			fileInfo.filename = entry.path().filename().c_str();
			fileInfo.fileSize = entry.file_size();
			fileInfo.depth = currentDepth + 1;

			contents.Add(fileInfo);
		}
	}
	catch (fs::filesystem_error& e) {
		UE_LOG(FileSystem, Error, TEXT("%s"), UTF8_TO_TCHAR(e.what()));
	}

	contents.Sort([](const FFileInfo& fileA, const FFileInfo& fileB) { 
		FString stringA = fileA.filename;
		FString stringB = fileB.filename;

		int32 res = stringA.Compare(stringB);

		if (res < 0)
		{
			return false;
		}
		else if (res > 0)
		{
			return true;
		}
		else
		{
			return true;
		}
		});

	return contents;
}

void UBrowser::SetCurrentDir(FString dir, int32 depth)
{
	currentPath = fs::path(std::string(TCHAR_TO_UTF8(*dir)));
	//currentPath /= std::string(TCHAR_TO_UTF8(*dir));
	currentDepth = depth;
}

void UBrowser::ReturnToUpperDir()
{
	if (currentDepth > 0)
	{
		currentPath = currentPath.parent_path();
		currentDepth--;
	}
}

FString UBrowser::GetCurrentDir()
{
	return FString(currentPath.c_str());
}

int32 UBrowser::GetCurrectDepth()
{
	return currentDepth;
}

void UBrowser::CopyFiles(TArray<FFileInfo> files)
{
	try
	{
		for (FFileInfo fileInfo : files) {
			auto source = TCHAR_TO_UTF8(*(fileInfo.fullPath));
			auto destination = currentPath.string() + "\\" + std::string(TCHAR_TO_UTF8(*(fileInfo.filename)));
			fs::copy(source, destination, fs::copy_options::none);
		}
	}
	catch (fs::filesystem_error& e) {
		UE_LOG(FileSystem, Error, TEXT("%s"), UTF8_TO_TCHAR(e.what()));
	}
}

void UBrowser::RemoveFiles(TArray<FFileInfo> files)
{
	try
	{
		for (FFileInfo fileInfo : files) {
			auto path = TCHAR_TO_UTF8(*(fileInfo.fullPath));
			fs::remove_all(path);
		}
	}
	catch (fs::filesystem_error& e) {
		UE_LOG(FileSystem, Error, TEXT("%s"), UTF8_TO_TCHAR(e.what()));
	}
}
