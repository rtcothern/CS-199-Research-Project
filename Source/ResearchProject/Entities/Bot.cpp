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
	apFrequency = 1;
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
	Goal g3 = Goal(Goal::Goal_Type::Live, this);
	Goal g4 = Goal(Goal::Goal_Type::Defend, this);
	goals.Emplace(g1);
	goals.Emplace(g2);
	goals.Emplace(g3);
	goals.Emplace(g4);

	worldModel = WorldModel(goals);

	planner = new ActionPlanner();

	apTimer = 0;

	Super::BeginPlay();
}

// Called every frame
void ABot::Tick( float DeltaTime )
{
	if (apTimer >= apFrequency){
		//apTimer -= apFrequency;
		apTimer = 0;
		distanceToEnd = distanceToEnd > fieldWidth ? fieldWidth : distanceToEnd;
		executeNextAction();
	}
	else{
		apTimer += DeltaTime;
	}
	worldModel.updateGoals(DeltaTime);
	Super::Tick( DeltaTime );
}

void ABot::executeNextAction(){
	TArray<Action*> possibleActions;
	for (TActorIterator<AUnit> unitItr(GetWorld()); unitItr; ++unitItr){
		if (unitItr->team != this->team && unitItr->GetUniqueID() != this->GetUniqueID()
			&& unitItr->GetHorizontalDistanceTo(this) <= aggroRange)
			possibleActions.Append(unitItr->getExposedActions());
	}
	for (TActorIterator<AEndZone> unitItr(GetWorld()); unitItr; ++unitItr){
		if (unitItr->team != this->team && unitItr->GetUniqueID() != this->GetUniqueID())
			possibleActions.Append(unitItr->getExposedActions());
	}
	if (possibleActions.Num() > 0){
		worldModel.setActions(possibleActions);
		Action* nextAction = planner->planAction(worldModel, 2);
		if (nextAction)
			nextAction->executeAction(this);
	} 
}

void ABot::acquireExp(uint8 exp){
	uint32 toAdd = exp;
	while (toAdd > 0){
		if ((int32)(exp + toAdd) >= level){
			toAdd -= level;
			level++;
			this->GetCharacterMovement()->MaxWalkSpeed += 50;
		}
		else{
			exp += toAdd;
			toAdd = 0;
		}
	}
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
	//Blank intentionally
}

void ABot::scoreKill(ABot* victim){
	goldEarned += victim->getGoldWorth();
	acquireExp(victim->getExpWorth());
	victim->Die();
}
void ABot::scoreEndZone(AEndZone* enemyEndZone){
	if (enemyEndZone && friendlyEndZone){
		worldModel.applyAction(enemyEndZone->getExposedActions()[0]);
		goldEarned += enemyEndZone->getGoldWorth();
		acquireExp(enemyEndZone->getExpWorth());
		Respawn();
	}
}
void ABot::Die(){
	alive = false;
	Respawn();
}
void ABot::Respawn(){
	this->SetActorLocation(friendlyEndZone->GetActorLocation());
}

float ABot::getExpInsist(){
	for (auto g : worldModel.getCharGoals()){
		if (g.goal_type == Goal::Goal_Type::Exp)
			return g.getInsistence();
	}
	return 0;
}
float ABot::getGoldInsist(){
	for (auto g : worldModel.getCharGoals()){
		if (g.goal_type == Goal::Goal_Type::Gold)
			return g.getInsistence();
	}
	return 0;
}
