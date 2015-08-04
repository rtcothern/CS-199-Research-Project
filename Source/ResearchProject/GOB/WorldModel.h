// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Action.h"
#include <vector>

/**
 * 
 */
class RESEARCHPROJECT_API WorldModel
{
public:
	WorldModel();
	WorldModel(std::vector<Action> applicableActions, std::vector<Goal> charGoals);
	~WorldModel();

	int32 calculateDC();
	Action* nextAction();
	void applyAction(Action* action);

protected:
	std::vector<Action> applicableActions;
	std::vector<Goal> charGoals;
	int32 currentActionIndex = 0;
};
