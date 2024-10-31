// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include <Engine/StaticMeshActor.h>
#include "MyProjectGameMode.generated.h"

UCLASS(minimalapi)
class AMyProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMyProjectGameMode();


	TArray<AStaticMeshActor*> ListaDeCubos;
	void SpawnStaticMeshCube(UWorld* World, FVector Location, FRotator Rotation);
};



