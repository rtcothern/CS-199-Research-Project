// Fill out your copyright notice in the Description page of Project Settings.

#include "ResearchProject.h"
#include "../Entities/Unit.h"
#include "../Entities/Bot.h"
#include "WorldModel.h"

WorldModel::WorldModel(){

}
WorldModel::WorldModel(const WorldModel & copy){
	charGoals = copy.charGoals;
	applicableActions = copy.applicableActions;
	disabledActions = copy.disabledActions;
	ownerLocation = copy.ownerLocation;
	ownerSpeed = copy.ownerSpeed;
	currentActionIndex = 0;
}
WorldModel::WorldModel(TArray<Goal> charGoals)// , FResource charResource)
{
	this->charGoals = charGoals;
}

WorldModel::~WorldModel()
{
}

float WorldModel::calculateDC(){
	float dc = 0;
	for (auto g : charGoals){
		dc += g.getDC();
	}
	return dc;
}
Action* WorldModel::nextAction(){
	//Only consider actions the character possesses enough resource to execute
	/*while (currentActionIndex < applicableActions.Num() && applicableActions[currentActionIndex]->getResourceCost() > charResource.amount){
		currentActionIndex++;
	}*/

	//Search for the next available action
	while (currentActionIndex < applicableActions.Num() && disabledActions[currentActionIndex])
		currentActionIndex++;
	//If we haven't run out of actions, return the current action and move the index forward
	if (currentActionIndex < applicableActions.Num()){
		return applicableActions[currentActionIndex++];
	}

	//Otherwise there are no actions left to consider
	else {
		 return nullptr;
	}
}

//A value of -1 for oldActionIndex indicates no disabled action
void WorldModel::applyAction(Action* action, int8 oldActionIndex){
	if (oldActionIndex >= 0 && action->action_type == Action::Action_Type::Kill){
		action->evalDuration(ownerLocation, ownerSpeed);
		disabledActions[oldActionIndex] = true;
	}
	for (auto & g : charGoals){
		g.applyAction(action);
	}

	//Manage the characters resource as a result of the action's cost and duration
	/*charResource.amount -= action->getResourceCost();
	charResource.amount += charResource.regenRate*action->getDuration();
	if (charResource.amount > charResource.maxAmount)
		charResource.amount = charResource.maxAmount;*/
}

void WorldModel::setActions(TArray<Action*> actions){
	applicableActions = actions;
	disabledActions.Init(false, applicableActions.Num());
}

void WorldModel::setBotAttr(FVector location, float speed){
	ownerLocation = location;
	ownerSpeed = speed;
}


void WorldModel::updateGoals(float deltaTime){
	for (auto & g : charGoals){
		g.update(deltaTime);
	}
}

int8 WorldModel::getCurrActInd(){
	return currentActionIndex; 
};
