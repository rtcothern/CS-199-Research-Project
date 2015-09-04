// Code copyright © Raymond Cothern, 2015

#include "ResearchProject.h"
#include "Goal.h"
#include "Action.h"
#include "../Entities/Bot.h"

Action::Action(float duration){
	this->duration = duration;
	resourceCost = 0;
}

Action::Action(float duration, uint16 resourceCost){
	this->duration = duration;
	this->resourceCost = resourceCost;
}

Action::Action(Action_Type type, AUnit *executeeUnit)
{
	resourceCost = 0;
	duration = 0;
	action_type = type;
	executee = executeeUnit;
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

float Action::getExpEffect(AUnit * const executor){
	float result = 0;
	switch (action_type){
		case Action_Type::Kill:
		{
			FParagonProgression *progression = (FParagonProgression*)executor->progression;
			float ratio = executee->getExpWorth() / progression->getRemainingExp();
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
float Action::getGoldEffect(AUnit * const executor){
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
			//TODO
			break;
		}
	}
	return result;
}
float Action::getLiveEffect(AUnit * const executor){
	float result = 0;
	switch (action_type){
		case Action_Type::Kill:
		{
			FParagonProgression *progExecutor = (FParagonProgression*)executor->progression;
			//FParagonProgression *progExecutee = (FParagonProgression*)executor->progression;
			//Temporary fix, this will work because of the values for exp for units and endzones, but should be fixed in the progression patch
			//Some sort of THREAT indicator interface would be a good idea here
			//!!!!!!!!!!!!!!!!! TODO !!!!!!!!!!!!!!!!!!!!!!!!!
			float ratio = progExecutor->level / executee->getExpWorth(); //progExecutee->level;
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
float Action::getDefendEffect(AUnit * const executor){
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
		executor->runAttackBehavior(executee);
		break;
	case Action_Type::Evade:
		break;
	case Action_Type::Move_Toward:
		break;
	}
}
