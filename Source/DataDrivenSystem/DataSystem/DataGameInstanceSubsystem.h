// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/DataTable.h"
#include "DataGameInstanceSubsystem.generated.h"



/**
 * 数据驱动子系统，游戏开始时从文件里加载数据覆盖相关数据
 *
 * 打算把所有配置的数据通过该子系统进行管理，即有配置文件时，读取配置覆盖数据，
 * 没有配置文件时，使用一套默认数据
 *
 * 目前只实现了csv文件覆盖数据表
 */
UCLASS()
class DATADRIVENSYSTEM_API UDataGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	/**
	 * @brief 加载csv文件覆盖数据表；csv文件不存在时使用默认数据表数据
	 *
	 * 打包后依然可以从csv文件覆盖数据表
	 * 注意：数据表里不建议使用中文，测试发现有中文时，从数据表里导出的csv文件由逗号分割，对操作表格不友好
	 *
	 */
	static TArray<UDataTable*> PDTArray;
	static bool LoadCsvAsDataTable(const FString CSVFilePath, const TCHAR* DTRef, UScriptStruct* DTStruct);


public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/**
	 * @brief 开始加载配置文件覆盖数据；
	 * 测试发现在子系统初始化时机点调用会导致打包出来后覆盖失败；
	 * 所以改在GameMode的BeginPlay时机点调用,所以数据只有在服务器才会被覆盖
	 * 数据表里建议只存放文本数据，而不要存放大量actor等资产，因为游戏开始时就会加载数据表相关资产到内存。
	 */
	static void StartLoadData();
};

