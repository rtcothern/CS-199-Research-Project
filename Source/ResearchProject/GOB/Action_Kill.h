#pragma once
#include "Action.h"

class RESEARCHPROJECT_API Action_Kill : public Action
{
public:
	Action_Kill(uint16 expGain, uint16 goldGain);
	~Action_Kill();

	virtual float getExpEffect(uint16 currentExp);
	virtual float getGoldEffect(uint16 currentGold);
	/*virtual float getLiveEffect(const Goal* goal);
	virtual float getPushEffect(const Goal* goal);
*/
private:
	uint16 expGain, goldGain;
};

