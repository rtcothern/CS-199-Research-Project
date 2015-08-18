// Fill out your copyright notice in the Description page of Project Settings.

#include "ResearchProject.h"
#include "../GOB/Action.h"
#include "../GOB/ActionPlanner.h"
#include "../GOB/Goal_Exp.h"
#include "EngineUtils.h"
#include "Bot.h"

#include <sstream>
#include <string>


// Sets default values
ABot::ABot() : AUnit()
{
	PrimaryActorTick.bCanEverTick = true;

	progression = new Attributes::FParagonProgression();

	TArray<Goal*> goals;
	Goal *g = new Goal_Exp(((Attributes::FParagonProgression*)progression)->getExpForNextLevel());
	goals.Emplace(g);

	worldModel = WorldModel(goals);
}
ABot::~ABot(){
	delete planner;
}

// Called when the game starts or when spawned
void ABot::BeginPlay()
{
	//UE_LOG(LogTemp, Warning, TEXT("Bot is beginning to play!"));

	planner = new ActionPlanner();
	Super::BeginPlay();
}

// Called every frame
void ABot::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

//// Called to bind functionality to input
//void ABot::SetupPlayerInputComponent(class UInputComponent* InputComponent)
//{
//	Super::SetupPlayerInputComponent(InputComponent);
//
//}

void ABot::executeNextAction(){
	TArray<Action*> possibleActions;
	for (TActorIterator<AUnit> unitItr(GetWorld()); unitItr; ++unitItr){
		if (unitItr->GetUniqueID() != this->GetUniqueID())
			possibleActions.Append(unitItr->getExposedActions());
	}
	worldModel.setActions(possibleActions);
	Action* nextAction = planner->planAction(worldModel, 5);

}