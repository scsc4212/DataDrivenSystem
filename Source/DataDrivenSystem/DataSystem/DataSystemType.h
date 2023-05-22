// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DataSystemType.generated.h"

//数据系统相关的结构体等相关数据类型在此类里定义
 


 /**
  * 数据表结构体
  */
USTRUCT(BlueprintType)
struct FDTTest : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool Enable;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int32 Count;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString Name;
};
