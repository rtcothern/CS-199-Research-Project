// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "ResearchProjectGameMode.generated.h"

UCLASS(minimalapi)
class AResearchProjectGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AResearchProjectGameMode();

	/** Current gold of Team 1. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Game_Attributes)
		int32 Team_1_Gold;
	/** Current gold of Team 2. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Game_Attributes)
		int32 Team_2_Gold;
	/** The amount of gold a team needs to win */
	UPROPERTY(BlueprintReadOnly, Category = Game_Attributes)
		int32 Gold_To_Win;
	UPROPERTY(BlueprintReadOnly, Category = Game_Attributes)
		int32 avgLevel;

	UFUNCTION(BlueprintCallable, Category = Game_Attributes)
		void updateGameAttributes(int32 t1g, int32 t2g, int32 avgLvl);
};



