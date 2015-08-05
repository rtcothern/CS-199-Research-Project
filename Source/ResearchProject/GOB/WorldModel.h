// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <vector>
#include "Action.h"
#include "Goal.h"

using namespace std;

//class Resource;

class RESEARCHPROJECT_API WorldModel
{
public:
	WorldModel();
	WorldModel(vector<Action> applicableActions, vector<Goal> charGoals);
	~WorldModel();

	float calculateDC();
	Action* nextAction();
	void applyAction(Action* action);

private:
	vector<Action> applicableActions;
	vector<Goal> charGoals;
	uint8 currentActionIndex = 0;
	//Resource charResource;
};
