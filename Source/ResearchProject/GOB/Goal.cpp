 // Code copyright © Raymond Cothern, 2015

#include "ResearchProject.h"
#include "Action.h"
#include "Goal.h"
#include "Entities/Bot.h"

Goal::Goal()
{
}
Goal::Goal(Goal_Type type, ABot *ownerBot)
{
	goal_type = type;
	owner = ownerBot;
	insistence = 5;
	changePerMinute = 0;
}
float Goal::getDC() const{
	float result = 0;
	switch (goal_type)
	{
	case Goal_Type::Gold:
		result = insistence*insistence*insistence;
		break;
	case Goal_Type::Exp:
		result = insistence*insistence;
		break;
	case Goal_Type::Live:
		result = insistence*insistence*insistence;
		break;
	case Goal_Type::Defend:
		result = 1.5*insistence*insistence;
		break;
	}
	return result; 
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

	insistence -= directChange;
	insistence += passiveChange;
	if (insistence > maxInsistence){
		insistence = maxInsistence;
	}
	else if (insistence < 0){
		insistence = 0;
	}
}