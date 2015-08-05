// Fill out your copyright notice in the Description page of Project Settings.

#include "ResearchProject.h"
#include "WorldModel.h"

WorldModel::WorldModel(){

}
WorldModel::WorldModel(vector<Action> applicableActions, vector<Goal> charGoals)
{
	this->applicableActions = applicableActions;
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
	if (currentActionIndex < applicableActions.size()) {
		return &applicableActions[currentActionIndex++];
	}
	else {
		 return nullptr;
	}
}

//TODO: Allow for applying an action to disable other actions
void WorldModel::applyAction(Action* action){
	for (auto & g : charGoals){
		g.applyAction(*action);
	}
	for (auto &a : applicableActions){
		/*if ()*/
	}
}
