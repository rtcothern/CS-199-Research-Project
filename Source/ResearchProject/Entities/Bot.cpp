// Fill out your copyright notice in the Description page of Project Settings.

#include "ResearchProject.h"
#include "../GOB/Action.h"
#include "../GOB/ActionPlanner.h"
#include "EngineUtils.h"
#include "Bot.h"
#include "EndZone.h"


// Sets default values
ABot::ABot() : AUnit()
{
	PrimaryActorTick.bCanEverTick = true;
	exp = 0;
	level = 1;
}
ABot::~ABot(){
	delete planner;
}

// Called when the game starts or when spawned
void ABot::BeginPlay()
{
	exp = 0;
	level = 1;

	TArray<Goal> goals;
	Goal g1 = Goal(Goal::Goal_Type::Exp, this);
	Goal g2 = Goal(Goal::Goal_Type::Gold, this);
	goals.Emplace(g1);
	goals.Emplace(g2);

	worldModel = WorldModel(goals);

	planner = new ActionPlanner();

	Super::BeginPlay();
}

// Called every frame
void ABot::Tick( float DeltaTime )
{
	if (exp >= level){
		exp -= level++;
	}
	Super::Tick( DeltaTime );
}

void ABot::executeNextAction(){
	TArray<Action*> possibleActions;
	for (TActorIterator<AUnit> unitItr(GetWorld()); unitItr; ++unitItr){
		if (unitItr->team != this->team && unitItr->GetUniqueID() != this->GetUniqueID())
			possibleActions.Append(unitItr->getExposedActions());
	}
	for (TActorIterator<AEndZone> unitItr(GetWorld()); unitItr; ++unitItr){
		if (unitItr->team != this->team && unitItr->GetUniqueID() != this->GetUniqueID())
			possibleActions.Append(unitItr->getExposedActions());
	}
	worldModel.setActions(possibleActions);
	Action* nextAction = planner->planAction(worldModel, 2);
 	nextAction->executeAction(this);
}

uint16 ABot::getExpForNextLevel(){
	return level;
}
uint16 ABot::getRemainingExp(){
	return getExpForNextLevel() - exp;
}
uint16 ABot::getExpWorth(){
	return getExpForNextLevel();
}
uint16 ABot::getGoldWorth(){
	return baseGoldWorth + ((fieldWidth-distanceToEnd) / zoneWidth - 0.5);
}

void ABot::runAttackBehavior_Implementation(AUnit* target){
	//Blank intentionally
}
void ABot::runMoveTowardBehavior_Implementation(AEndZone* moveTarget){
}