// Code copyright © Raymond Cothern, 2015

#pragma once

class Goal;
class GobObject;
class ABot;

/**
 * 
 */
class RESEARCHPROJECT_API Action
{
public:
	enum class Action_Type{
		Kill,
		Evade,
		Move_Toward,
		Defend_Area
	};

	~Action();
	Action(Action_Type type, GobObject *executeeObject);

	//Get the duration of the action in minutes
	float getDuration() const;

	Action_Type action_type;

	uint16 getResourceCost();

	float getExpEffect(ABot * const executor);
	float getGoldEffect(ABot * const executor);
	float getLiveEffect(ABot * const executor);
	float getDefendEffect(ABot * const executor);

	void executeAction(class ABot *executor);

protected:
	Action(float duration);
	Action(float duration, uint16 resourceCost);
	
	GobObject *executee;

	float duration;
	uint16 resourceCost;

	const float maxInsistEffect = 2;
	const float maxGoldGain = 15;
};
