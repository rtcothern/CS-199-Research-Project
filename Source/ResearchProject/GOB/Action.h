// Code copyright © Raymond Cothern, 2015

#pragma once
#include <unordered_map>

class Goal;
class AUnit;
/**
 * 
 */
class RESEARCHPROJECT_API Action
{
public:
	enum class Action_Type{
		Kill,
		Evade,
		Move_Toward
	};

	~Action();
	Action(Action_Type type, AUnit *executeeUnit);

	//Get the duration of the action in minutes
	float getDuration() const;

	Action_Type action_type;

	uint16 getResourceCost();

	float getExpEffect(AUnit * const executor);
	float getGoldEffect(AUnit * const executor);
	float getLiveEffect(AUnit * const executor);
	float getDefendEffect(AUnit * const executor);

	void executeAction(class ABot *executor);

protected:
	Action(float duration);
	Action(float duration, uint16 resourceCost);
	
	AUnit *executee;

	float duration;
	uint16 resourceCost;

	const float maxInsistEffect = 2;
	const float maxGoldGain = 15;
};
