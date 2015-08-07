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
	Action(FName name, float duration, uint16 resourceCost);
	Action();
	~Action();

	//Retrieve the actions effect on this specific goal (if any)
	float getEffectOnGoal(const uint16 goalId) const;

	//Get the duration of the action in minutes
	float getDuration() const;

	//Add a pairing of a goal and an effect
	void addGoalEffect(uint16 goalId, float delta);

	uint16 getResourceCost();

protected:
	float duration;
	FName name;
	std::unordered_map<uint16, float> goalEffects;
	uint16 resourceCost;
};
