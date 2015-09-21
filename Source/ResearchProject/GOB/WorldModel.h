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
	WorldModel(TArray<Goal> charGoals);// , FResource charResource);
	WorldModel(const WorldModel & copy);
	~WorldModel();

	float calculateDC();
	Action* nextAction();
	void applyAction(Action* action, int8 oldActionIndex);
	void setActions(TArray<Action*> actions);
	void updateGoals(float deltaTime);

	TArray<Goal> getCharGoals(){ return charGoals; };

	void setBotAttr(FVector location, float speed);

	int8 getCurrActInd();

private:
	TArray<Action*> applicableActions;
	TArray<Goal> charGoals;
	int8 currentActionIndex = 0;
	FVector ownerLocation;
	float ownerSpeed;
	TArray<bool> disabledActions;
};
