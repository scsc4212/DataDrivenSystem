// Fill out your copyright notice in the Description page of Project Settings.


#include "DataGameInstanceSubsystem.h"
#include "DataSystemType.h"



TArray<UDataTable*>UDataGameInstanceSubsystem::PDTArray;


bool UDataGameInstanceSubsystem::LoadCsvAsDataTable(const FString CSVFilePath, const TCHAR* DTRef,
													UScriptStruct* DTStruct)
{
	const FString CSVFileRealPath = FPaths::ProjectDir() / CSVFilePath;
	FString CSVFileContent;

	//csv文件存在不
	if (!FFileHelper::LoadFileToString(CSVFileContent, *CSVFileRealPath))
	{
		return false;
	}

	UDataTable* LocDataTable = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), nullptr, DTRef));

	if (LocDataTable->RowStruct != DTStruct)
	{
		//这里可以替代成自定义的打印函数
		GLog->Log("SC9528: 数据表和CSV文件的结构体类型不一致！");
		return false;
	}

	//覆盖数据表
	LocDataTable->CreateTableFromCSVString(CSVFileContent);


	//搞个静态数组保存引用，防止被垃圾回收导致数据失效
	PDTArray.Add(LocDataTable);

	return true;
}


void UDataGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

}

void UDataGameInstanceSubsystem::StartLoadData()
{
	LoadCsvAsDataTable("/Data/Test.csv", TEXT("DataTable'/Game/DT_Test.DT_Test'"), FDTTest::StaticStruct());
	
}




