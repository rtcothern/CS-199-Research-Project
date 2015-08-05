// Fill out your copyright notice in the Description page of Project Settings.

#include "ResearchProject.h"
#include "Action.h"
#include "Goal.h"

uint16 Goal::highestId = 0;
// Sets default values
Goal::Goal(FName name)
{
	this->name = name;
	insistence = 0;
	changePerMinute = 0;
	id = highestId++;
}
Goal::Goal(FName name, float insist)
{
	this->name = name;
	insistence = insist;
	changePerMinute = 0;
	id = highestId++;
}

float Goal::getDC(){
	return insistence*insistence;
}

float Goal::getPassiveChange(){
	return changePerMinute;
}
uint16 Goal::getId(){
	return id;
}
void applyAction(const Action & action){

}

