// Fill out your copyright notice in the Description page of Project Settings.

#include "ResearchProject.h"
#include "Action.h"

Action::Action(String name, int32 durationMS) : goalEffects()
{
	this->name = name;
	this->durationMS = durationMS;
}
Action::Action() : goalEffects()
{
	durationMS = 0;
}

Action::~Action()
{
}

int32 Action::getEffectOnGoal(const int32 &goalId){
	return goalEffects[goalId];
}
int32 Action::getDuration(){
	return durationMS;
}

void Action::addGoalEffect(int32 goalId, int32 delta){
	goalEffects.emplace(goalId, delta);
}


