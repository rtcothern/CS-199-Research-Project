// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <unordered_map>

class Goal;
/**
 * 
 */
class RESEARCHPROJECT_API Action
{
public:
	~Action();
	Action();
	//Get the duration of the action in minutes
	float getDuration() const;

	uint16 getResourceCost();

	virtual float getExpEffect(uint16 expNeededForLevel) { return 0; };
	virtual float getGoldEffect(uint16 currentGold) { return 0; };
	virtual float getLiveEffect(const Goal* goal) { return 0; };
	virtual float getPushEffect(const Goal* goal) { return 0; };

protected:
	Action(float duration);
	Action(float duration, uint16 resourceCost);
	
	float duration;
	uint16 resourceCost;
};
