// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "WorldModel.h"

/**
 * 
 */
class RESEARCHPROJECT_API ActionPlanner
{
public:
	ActionPlanner();
	~ActionPlanner();

	Action planAction(const WorldModel& world, const int32& maxDepth);
};
