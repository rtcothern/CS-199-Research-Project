// Fill out your copyright notice in the Description page of Project Settings.

#include "ResearchProject.h"
#include "WorldModel.h"

WorldModel::WorldModel(){

}
WorldModel::WorldModel(std::vector<Action> applicableActions, std::vector<Goal> charGoals)
{
	this->applicableActions = applicableActions;
	this->charGoals = charGoals;
}

WorldModel::~WorldModel()
{
}

int32 WorldModel::calculateDC(){
	int32 dc = 0;
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
	for (Goal &g : charGoals){
		int32 directChange = action->getEffectOnGoal(g.getId());
		int32 passiveChange = g.getPassiveChange() * action->getDuration();
		g.modifyInsistence(directChange);
		g.modifyInsistence(passiveChange);
	}
}
