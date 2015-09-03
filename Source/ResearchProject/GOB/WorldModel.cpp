// Fill out your copyright notice in the Description page of Project Settings.

#include "ResearchProject.h"
#include "../Entities/Unit.h"
#include "WorldModel.h"

WorldModel::WorldModel(){

}
WorldModel::WorldModel(const WorldModel & copy){
	charGoals = copy.charGoals;
	applicableActions = copy.applicableActions;
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
	//If we haven't run out of actions
	if (currentActionIndex < applicableActions.Num()){
		return applicableActions[currentActionIndex++];
	}
	//Otherwise there are no actions left to consider
	else {
		 return nullptr;
	}
}

void WorldModel::applyAction(Action* action){
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
}

void WorldModel::updateGoals(Unit *character){
	for (auto g : charGoals){

	}
}