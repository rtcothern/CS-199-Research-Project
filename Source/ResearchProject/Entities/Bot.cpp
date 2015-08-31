// Fill out your copyright notice in the Description page of Project Settings.

#include "ResearchProject.h"
#include "../GOB/Action.h"
#include "../GOB/ActionPlanner.h"
#include "../GOB/Goal_Exp.h"
#include "../GOB/Goal_Gold.h"
#include "EngineUtils.h"
#include "Bot.h"


// Sets default values
ABot::ABot() : AUnit()
{
	PrimaryActorTick.bCanEverTick = true;
}
ABot::~ABot(){
	delete planner;
}

// Called when the game starts or when spawned
void ABot::BeginPlay()
{
	progression = new FParagonProgression();

	TArray<Goal*> goals;
	Goal *g1 = new Goal_Exp(((FParagonProgression*)progression)->getExpForNextLevel());
	Goal *g2 = new Goal_Gold(((FParagonProgression*)progression)->gold);
	goals.Emplace(g1);
	goals.Emplace(g2);

	worldModel = WorldModel(goals);

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
	nextAction->executeAction(this);
}

void ABot::runAttackBehavior_Implementation(AUnit* target){

}