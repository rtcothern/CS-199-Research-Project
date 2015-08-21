// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
class Action;

class RESEARCHPROJECT_API Goal
{
	
public:	
	~Goal(){};
	Goal();
	//Goal(float startingInsistence, float changePerMinute);

	//Calculate the current discontentment contribution from this goal
	virtual float getDC() const;

	//Get the passive change per minute in this goal
	float getPassiveChange() const { return changePerMinute; };

	uint16 getId() const { return id; };
	float getInsistence() const { return insistence; };

	//Apply the specified action to this goal and observe its effect
	virtual void applyAction(Action *action);

	virtual void update(class AUnit* character) = 0;

protected:
	const float maxInsistence = 10;
	float insistence, changePerMinute;
	uint16 id;
	static uint16 highestId;
	bool bEnabled;
};