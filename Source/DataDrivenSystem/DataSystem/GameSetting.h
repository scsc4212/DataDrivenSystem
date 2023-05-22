// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GameSetting.generated.h"

/**
 * UE配置工具,在项目设置里配置数据,配置文件默认存放在config目录下
 *
 * 打包出来后依然可以通过配置文件覆盖数据，但配置文件路径改变到了save目录下了（具体啥目录忘记了）
 *
 * ？？？想修改其默认存放路径，但不知道怎么弄
 */

UCLASS(config = UGameSetting, DefaultConfig)
class DATADRIVENSYSTEM_API UGameSetting : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	/** Gets the settings container name for the settings, either Project or Editor */
	virtual FName GetContainerName() const override { return TEXT("Project"); }
	/** Gets the category for the settings, some high level grouping like, Editor, Engine, Game...etc. */
	virtual FName GetCategoryName() const override { return TEXT("Realis数据配置"); }
	/** The unique name for your section of settings, uses the class's FName. */
	virtual FName GetSectionName() const override { return TEXT("数据"); }

	
	UGameSetting();

	UFUNCTION(BlueprintPure, DisplayName="GetGameSetting")
	static UGameSetting* Get(){return GetMutableDefault<UGameSetting>();}


	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "测试")
		bool Enable = false;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "测试")
		int32 Count= 10;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "测试")
		FString Name = "SC9528";

	
};