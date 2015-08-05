// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <unordered_map>

/**
 * 
 */
class RESEARCHPROJECT_API Action
{
public:
	Action(FName name, float duration);
	Action();
	~Action();

	//Retrieve the actions effect on this specific goal (if any)
	float getEffectOnGoal(const uint16 &goalId);

	//Get the duration of the action in minutes
	float getDuration();

	//Add a pairing of a goal and an effect
	void addGoalEffect(uint16 goalId, float delta);

protected:
	float duration;
	FName name;
	std::unordered_map<uint16, float> goalEffects;
};
