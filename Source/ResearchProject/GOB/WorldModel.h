// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <vector>
#include "Action.h"
#include "Goal.h"
#include "../Entities/UnitProperties.h"

using namespace std;


class RESEARCHPROJECT_API WorldModel
{
public:
	WorldModel();
	WorldModel(vector<Action> applicableActions, vector<Goal> charGoals, FResource charResource);
	~WorldModel();

	float calculateDC();
	Action* nextAction();
	void applyAction(Action* action);

	//void setResource(uint)

private:
	vector<Action> applicableActions;
	vector<Goal> charGoals;
	uint8 currentActionIndex = 0;
	FResource charResource;
};
