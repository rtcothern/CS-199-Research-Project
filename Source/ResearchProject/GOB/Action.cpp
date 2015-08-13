// Fill out your copyright notice in the Description page of Project Settings.

#include "ResearchProject.h"
#include "Goal.h"
#include "Action.h"

Action::Action(float duration){
	this->duration = duration;
	resourceCost = 0;
}

Action::Action(float duration, uint16 resourceCost){
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

float Action::getDuration() const{
	return duration;
}

uint16 Action::getResourceCost(){
	return resourceCost;
}