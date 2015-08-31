#pragma once
#include "Action.h"

class RESEARCHPROJECT_API Action_Kill : public Action
{
public:
	Action_Kill(float expGain, float goldGain, class AUnit *target);
	~Action_Kill();

	float getExpEffect(float expNeededForLevel);
	float getGoldEffect(float currentGold);
	/*virtual float getLiveEffect(const Goal* goal);
	virtual float getPushEffect(const Goal* goal);
	*/
	void executeAction(class ABot *executor);
private:
	float expGain, goldGain;
	class AUnit *target;
};

