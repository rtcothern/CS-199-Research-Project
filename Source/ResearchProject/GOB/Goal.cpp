// Fill out your copyright notice in the Description page of Project Settings.

#include "ResearchProject.h"
#include "Action.h"
#include "Goal.h"

uint16 Goal::highestId = 0;
Goal::Goal(float startingInsistence)
{
	insistence = startingInsistence;
	changePerMinute = 0;
	id = highestId++;
}
float Goal::getDC() const{
	return insistence*insistence;
}


void Goal::applyAction(Action * action){
	float passiveChange = changePerMinute * action->getDuration();
	insistence += passiveChange;
	if (insistence > maxInsistence){
		insistence = maxInsistence;
	}
	else if (insistence < 0){
		insistence = 0;
	}
}