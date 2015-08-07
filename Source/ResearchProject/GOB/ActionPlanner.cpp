// Fill out your copyright notice in the Description page of Project Settings.

#include "ResearchProject.h"
#include "WorldModel.h"
#include "Action.h"
#include "ActionPlanner.h"
#include <stack>

ActionPlanner::ActionPlanner()
{
}

ActionPlanner::~ActionPlanner()
{
}

Action ActionPlanner::planAction(const WorldModel& world, const int32& maxDepth){
	WorldModel* worlds = new WorldModel[maxDepth+1];
	Action* actions = new Action[maxDepth];

	worlds[0] = world;
	int32 currentDepth = 0;

	Action bestAction;
	int32 bestDC = INT32_MAX;
	std::stack<int32> heurDCS;
	heurDCS.push(bestDC);

	while (currentDepth >= 0){
		int32 currentDC = worlds[currentDepth].calculateDC();
		if (currentDC > heurDCS.top()){
			currentDepth--;
			heurDCS.pop();
			continue;
		}
		if (currentDepth >= maxDepth){
			if (currentDC < bestDC){
				bestDC = currentDC;
				bestAction = actions[0];
				currentDepth--;
				heurDCS.pop();
				continue;
			}
		}

		Action* nextAction = worlds[currentDepth].nextAction();
		if (nextAction){
			WorldModel nextWorld(worlds[currentDepth]);
			actions[currentDepth] = *nextAction;
			nextWorld.applyAction(nextAction);
			worlds[currentDepth + 1] = nextWorld;
			currentDepth++;
			heurDCS.push(currentDC);
		}
		else {
			currentDepth--;	
			heurDCS.pop();
		}
	}
	return bestAction;
}
