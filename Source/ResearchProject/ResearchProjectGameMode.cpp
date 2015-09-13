// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "ResearchProject.h"
#include "ResearchProjectGameMode.h"
#include "ResearchProjectPlayerController.h"
#include "ResearchProjectCharacter.h"

AResearchProjectGameMode::AResearchProjectGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AResearchProjectPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	NumBots = 4;
	Team_1_Gold = 0;
	Team_2_Gold = 0;
	Gold_To_Win = 300;
	NumPlayers = 0;
	MinRespawnDelay = 2;
	NumSpectators = 1;
}
void AResearchProjectGameMode::updateGameAttributes(int32 t1g, int32 t2g, int32 avgLvl){
	Team_1_Gold = t1g;
	Team_2_Gold = t2g;
	avgLevel = avgLvl;
}
