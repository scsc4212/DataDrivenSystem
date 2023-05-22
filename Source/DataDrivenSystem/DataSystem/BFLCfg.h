// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BFLCfg.generated.h"

/**
 * 读取MCGame.ini配置文件
 */
UCLASS()
class DATADRIVENSYSTEM_API UBFLCfg : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:

	//配置文件读取路径
	static FString MCGameFilePath;
	//配置文件内容
	static FString MCGameFileContent;
	
public:
	/**
	 * @brief 加载配置文件，通过 键 找到对应的 值
	 * @param KeyStr   键
	 * @param bOutputUELog   是否打印日志
	 * @return C++里调用通过FCString::Atoi转int32；FCString::Atof转float
	 */
	UFUNCTION(BlueprintCallable, Category = "BFLCfgFile")
	static FString LoadCfgItem(const FString KeyStr, bool bOutputUELog);


};


