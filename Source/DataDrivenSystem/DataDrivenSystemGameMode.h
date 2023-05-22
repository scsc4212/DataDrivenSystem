// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DataDrivenSystemGameMode.generated.h"

UCLASS(minimalapi)
class ADataDrivenSystemGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADataDrivenSystemGameMode();

	virtual void BeginPlay() override;
};



