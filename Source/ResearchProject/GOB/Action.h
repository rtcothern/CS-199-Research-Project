// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Goal.h"
#include <unordered_map>

/**
 * 
 */
class RESEARCHPROJECT_API Action
{
public:
	Action(String name, int32 durationMS);
	Action();
	~Action();

	int32 getEffectOnGoal(const int32 &goalId);
	int32 getDuration();
	void addGoalEffect(int32 goalId, int32 delta);

protected:
	/**
	The amount of milliseconds this action will take
	*/
	int32 durationMS;
	String name;
	std::unordered_map<int32, int32> goalEffects;
};
