// Fill out your copyright notice in the Description page of Project Settings.

#include "ResearchProject.h"
#include "Goal.h"

int32 Goal::highestId = 0;
// Sets default values
Goal::Goal(String name)
{
	this->name = name;
	insistence = 0;
	changePerMinute = 0;
	id = highestId++;
}
Goal::Goal(String name, int32 insist)
{
	this->name = name;
	insistence = insist;
	changePerMinute = 0;
	id = highestId++;
}

int32 Goal::getDC(){
	return insistence*insistence;
}
int32 Goal::getDCFromNewInsist(int32 newVal){
	return newVal*newVal;
}

int32 Goal::getPassiveChange(){
	return changePerMinute;
}
int32 Goal::getId(){
	return id;
}


