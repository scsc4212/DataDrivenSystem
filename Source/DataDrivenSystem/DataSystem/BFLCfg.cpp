// Fill out your copyright notice in the Description page of Project Settings.


#include "BFLCfg.h"
#include "Kismet/GameplayStatics.h"


//静态变量定义
FString UBFLCfg::MCGameFilePath = FPaths::ProjectDir() / TEXT("/Data/MCGame.ini");
FString UBFLCfg::MCGameFileContent;




FString UBFLCfg::LoadCfgItem(const FString KeyStr, bool bOutputUELog)
{
	FString VauleStr;

	if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*MCGameFilePath))
	{
		//读取过配置文件就不要再次去读取了，这也会导致运行时配置文件更新不能立即更新到游戏内
		//基本不存在运行时去更新配置文件
		if (MCGameFileContent.IsEmpty())
		{
			FFileHelper::LoadFileToString(MCGameFileContent, *MCGameFilePath);
		}

		VauleStr = UGameplayStatics::ParseOption(MCGameFileContent, KeyStr);

		if (VauleStr.IsEmpty())
		{
			if (bOutputUELog)
			{
				UE_LOG(LogTemp, Error, TEXT("读取配置文件失败: %s is Nothing"), *KeyStr);
			}
		}
		else
		{
			if (bOutputUELog)
			{
				UE_LOG(LogTemp, Log, TEXT("读取配置文件成功: %s = %s"), *KeyStr, *VauleStr);
			}
		}
	}else
	{
		if (bOutputUELog)
		{
			UE_LOG(LogTemp, Error, TEXT("配置文件不存在!"));
		}
	}

	return VauleStr;
}
