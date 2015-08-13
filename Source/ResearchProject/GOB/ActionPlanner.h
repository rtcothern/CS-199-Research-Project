// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class RESEARCHPROJECT_API ActionPlanner
{
public:
	ActionPlanner();
	~ActionPlanner();

	class Action* planAction(const class WorldModel& world, const int32& maxDepth);
};
