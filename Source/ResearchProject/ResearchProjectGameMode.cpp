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

	Team_1_Gold = 0;
	Team_2_Gold = 0;
	Gold_To_Win = 200;
	NumPlayers = 0;
	NumBots = 6;
	MinRespawnDelay = 2;
	NumSpectators = 1;
}