// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class Action;

class RESEARCHPROJECT_API Goal
{
	
public:	
	// Sets default values for this actor's properties
	Goal(FName name);
	Goal(FName name, float insist);
	Goal(){ id = highestId++; };
	~Goal(){};

	//Calculate the current discontentment contribution from this goal
	float getDC();

	//Get the passive change per minute in this goal
	float getPassiveChange();

	//Retrieve this goals unique ID
	uint16 getId();

	//Apply the specified action to this goal and observe its effect
	void applyAction(const Action & action);

	void modifyInsistence(float delta){ insistence += delta; };

protected:
	float insistence;
	float changePerMinute;
	uint16 id;
	static uint16 highestId;
	FName name;
};
