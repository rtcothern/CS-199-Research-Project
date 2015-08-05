// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <vector>
#include <memory>

using namespace std;

class Action;
class Goal;

class RESEARCHPROJECT_API WorldModel
{
	typedef shared_ptr<Action> spa;
	typedef shared_ptr<Goal> spg;
public:
	WorldModel();
	WorldModel(vector<shared_ptr<Action>> applicableActions, vector<shared_ptr<Goal>> charGoals);
	~WorldModel();

	float calculateDC();
	spa nextAction();
	void applyAction(Action* action);

private:
	vector<spa> applicableActions;
	vector<spg> charGoals;
	uint8 currentActionIndex = 0;
};
