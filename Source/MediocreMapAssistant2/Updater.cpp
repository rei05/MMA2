// Fill out your copyright notice in the Description page of Project Settings.

#include "Updater.h"
#include "FileManagerGeneric.h"
#include "Paths.h"
#include <windows.h>

bool UUpdater::updateUpdater()
{
	FString source = FPaths::ProjectDir()+"Updates/MediocreMapper/MediocreUpdater.exe";
	FString target = FPaths::ProjectDir() +"MediocreUpdater.exe";
	UE_LOG(LogTemp, Warning, TEXT("%s"), *source);
	if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*source))
	{
		IFileManager& fManager = FFileManagerGeneric::Get();
		fManager.Copy(*source,*target,true,true);
		return FPlatformFileManager::Get().GetPlatformFile().FileExists(*target);
	}
	return false;
}

FString UUpdater::getProjectVersion()
{
	FString ProjectVersion;
	GConfig->GetString(
		TEXT("/Script/EngineSettings.GeneralProjectSettings"),
		TEXT("ProjectVersion"), 
		ProjectVersion,
		GGameIni
	);
	return ProjectVersion;
}
