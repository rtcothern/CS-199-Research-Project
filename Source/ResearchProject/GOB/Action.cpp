// Fill out your copyright notice in the Description page of Project Settings.

#include "ResearchProject.h"
#include "Action.h"

Action::Action(FName name, float duration){
	this->name = name;
	this->duration = duration;
	resourceCost = 0;
}

Action::Action(FName name, float duration, uint16 resourceCost){
	this->name = name;
	this->duration = duration;
	this->resourceCost = resourceCost;
}

Action::Action()
{
	resourceCost = 0;
	duration = 0;
}

Action::~Action()
{
}

float Action::getEffectOnGoal(const uint16 goalId) const{
	float effect;
	try{
		effect = goalEffects.at(goalId);
	}
	catch(std::out_of_range e){
		effect = 0;//this just means there's no effect
	}
	return effect;
}
float Action::getDuration() const{
	return duration;
}

void Action::addGoalEffect(uint16 goalId, float delta){
	goalEffects.emplace(goalId, delta);
}

uint16 Action::getResourceCost(){
	return resourceCost;
}



