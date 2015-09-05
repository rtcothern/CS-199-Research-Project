// Code copyright © Raymond Cothern, 2015

#include "ResearchProject.h"
#include "Goal.h"
#include "Action.h"
#include "../Entities/Bot.h"
#include "../Entities/EndZone.h"

Action::Action(float duration){
	this->duration = duration;
	resourceCost = 0;
}

Action::Action(float duration, uint16 resourceCost){
	this->duration = duration;
	this->resourceCost = resourceCost;
}

Action::Action(Action_Type type, GobObject *executeeObject)
{
	resourceCost = 0;
	duration = 0;
	action_type = type;
	executee = executeeObject;
}

Action::~Action()
{
}

float Action::getDuration() const{
	return duration;
}

uint16 Action::getResourceCost(){
	return resourceCost;
}

float Action::getExpEffect(ABot * const executor){
	float result = 0;
	switch (action_type){
		case Action_Type::Kill:
		{
			float ratio = executee->getExpWorth() / executor->getRemainingExp();
			result = (ratio <=  1) ? ratio * maxInsistEffect : maxInsistEffect;
			break;
		}
		case Action_Type::Evade:
		{
			//TODO
			break;
		}
		case Action_Type::Move_Toward:
		{
			//TODO
			break;
		}
	}
	return result;
}
float Action::getGoldEffect(ABot * const executor){
	float result = 0;
	switch (action_type){
		case Action_Type::Kill:
		{
			float ratio = executee->getGoldWorth() / maxGoldGain;
			result = ratio * maxInsistEffect;
			break;
		}
		case Action_Type::Evade:
		{
			//TODO
			break;
		}
		case Action_Type::Move_Toward:
		{
			float ratio = executee->getGoldWorth() / maxGoldGain;
			result = ratio * (executor->distanceToEnd / executor->fieldWidth) * maxInsistEffect;
			break;
		}
	}
	return result;
}
float Action::getLiveEffect(ABot * const executor){
	float result = 0;
	switch (action_type){
		case Action_Type::Kill:
		{
			//Temporary fix, this will work because of the values for exp for units and endzones, but should be fixed in the progression patch
			//Some sort of THREAT indicator interface would be a good idea here
			//!!!!!!!!!!!!!!!!! TODO !!!!!!!!!!!!!!!!!!!!!!!!!
			float ratio = executor->level / executee->getExpWorth(); //progExecutee->level;
			result = -ratio * maxInsistEffect;
			break; 
		}
		
		case Action_Type::Evade:
		{
			//TODO
			break;
		}
		case Action_Type::Move_Toward:
		{
			//TODO
			break;
		}
	}
	return result;
}
float Action::getDefendEffect(ABot * const executor){
	float result = 0;
	switch (action_type){
		case Action_Type::Kill:
			//TODO
			break;
		case Action_Type::Evade:
		{
			//TODO
			break;
		}
		case Action_Type::Move_Toward:
		{
			//TODO
			break;
		}
	}
	return result;
}

void Action::executeAction(ABot *executor){
	switch (action_type){
	case Action_Type::Kill:
		executor->runAttackBehavior((AUnit*)executee);
		break;
	case Action_Type::Evade:
		break;
	case Action_Type::Move_Toward:
		executor->runMoveTowardBehavior((AEndZone*)executee);
		break;
	}
}
