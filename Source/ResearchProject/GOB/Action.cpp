// Fill out your copyright notice in the Description page of Project Settings.

#include "ResearchProject.h"
#include "Action.h"

Action::Action(FName name, float duration){
	this->name = name;
	this->duration = duration;
}
Action::Action()
{
	duration = 0;
}

Action::~Action()
{
}

float Action::getEffectOnGoal(const uint16 &goalId){
	return goalEffects[goalId];
}
float Action::getDuration(){
	return duration;
}

void Action::addGoalEffect(uint16 goalId, float delta){
	goalEffects.emplace(goalId, delta);
}


