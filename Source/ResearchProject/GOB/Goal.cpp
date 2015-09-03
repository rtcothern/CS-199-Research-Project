 // Code copyright © Raymond Cothern, 2015

#include "ResearchProject.h"
#include "Action.h"
#include "Goal.h"

Goal::Goal()
{
}
Goal::Goal(Goal_Type type, AUnit *ownerUnit)
{
	goal_type = type;
	owner = ownerUnit;
}
float Goal::getDC() const{
	return insistence*insistence;
}


void Goal::applyAction(Action * action){
	float directChange;
	switch (goal_type)
	{
	case Goal_Type::Gold:
		directChange = action->getGoldEffect(owner);
		break;
	case Goal_Type::Exp:
		directChange = action->getExpEffect(owner);
		break;
	case Goal_Type::Live:
		directChange = action->getLiveEffect(owner);
		break;
	case Goal_Type::Defend:
		directChange = action->getDefendEffect(owner);
		break;
	default:
		directChange = 0;
		break;
	}

	float passiveChange = changePerMinute * action->getDuration();
	insistence += passiveChange;
	if (insistence > maxInsistence){
		insistence = maxInsistence;
	}
	else if (insistence < 0){
		insistence = 0;
	}
}