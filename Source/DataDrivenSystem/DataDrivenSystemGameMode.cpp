// Copyright Epic Games, Inc. All Rights Reserved.

#include "DataDrivenSystemGameMode.h"
#include "DataSystem/DataGameInstanceSubsystem.h"
#include "UObject/ConstructorHelpers.h"

ADataDrivenSystemGameMode::ADataDrivenSystemGameMode()
{
	/*// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}*/
}

void ADataDrivenSystemGameMode::BeginPlay()
{
	Super::BeginPlay();


	//开始加载配置文件覆盖数据
	GetGameInstance()->GetSubsystem<UDataGameInstanceSubsystem>()->StartLoadData();
}
