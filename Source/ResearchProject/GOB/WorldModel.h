// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <vector>
#include "Action.h"
#include "Goal.h"
#include "../Entities/UnitProperties.h"

class RESEARCHPROJECT_API WorldModel
{
public:
	WorldModel();
	WorldModel(TArray<Goal*> charGoals);// , FResource charResource);
	WorldModel(const WorldModel & copy);
	~WorldModel();

	float calculateDC();
	Action* nextAction();
	void applyAction(Action* action);
	void setActions(TArray<Action*> actions);
	void updateGoals(class Unit *character);

private:
	TArray<Action*> applicableActions;
	TArray<Goal*> charGoals;
	uint8 currentActionIndex = 0;
	//FResource charResource;
};
