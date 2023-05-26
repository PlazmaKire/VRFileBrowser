// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <filesystem>
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Browser.generated.h"
namespace fs = std::filesystem;

DECLARE_LOG_CATEGORY_EXTERN(FileSystem, Log, All);


USTRUCT(BlueprintType)
struct FFileInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "File Info Struct")
		FString fullPath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "File Info Struct")
		FString filename;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "File Info Struct")
		bool isDirectory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "File Info Struct")
		int32 depth;

		uint64 fileSize; //Cant see unsigned variables in blueprints
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VRFILEMANAGER_API UBrowser : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBrowser();

	UFUNCTION(BlueprintCallable, Category = "FileSystem")
		TArray<FFileInfo> GetCurrectDirFiles();

	UFUNCTION(BlueprintCallable, Category = "FileSystem")
		void SetCurrentDir(FString dir, int32 depth);

	UFUNCTION(BlueprintCallable, Category = "FileSystem")
		void ReturnToUpperDir();

	UFUNCTION(BlueprintCallable, Category = "FileSystem")
		FString GetCurrentDir();

	UFUNCTION(BlueprintCallable, Category = "FileSystem")
		int32 GetCurrectDepth();

	UFUNCTION(BlueprintCallable, Category = "FileSystem")
		void CopyFiles(TArray<FFileInfo> files);

	UFUNCTION(BlueprintCallable, Category = "FileSystem")
		void RemoveFiles(TArray<FFileInfo> files);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString startPath;

	fs::path currentPath;

	int32 currentDepth;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
