// Fill out your copyright notice in the Description page of Project Settings.

#include "ResearchProject.h"
#include "Action.h"
#include "Goal.h"
#include "WorldModel.h"

WorldModel::WorldModel(){

}
WorldModel::WorldModel(vector<shared_ptr<Action>> applicableActions, vector<shared_ptr<Goal>> charGoals)
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
		dc += g->getDC();
	}
	return dc;
}
WorldModel::spa WorldModel::nextAction(){
	if (currentActionIndex < applicableActions.size()) {
		return applicableActions[currentActionIndex++];
	}
	else {
		 return nullptr;
	}
}

//TODO: Allow for applying an action to disable other actions
void WorldModel::applyAction(Action* action){
	for (spg const g : charGoals){
		float directChange = action->getEffectOnGoal(g->getId());
		float passiveChange = g->getPassiveChange() * action->getDuration();
		g->modifyInsistence(directChange);
		g->modifyInsistence(passiveChange);
	}
}
