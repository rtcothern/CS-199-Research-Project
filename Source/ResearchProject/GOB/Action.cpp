// Code copyright © Raymond Cothern, 2015

#include "ResearchProject.h"
#include "Goal.h"
#include "Action.h"
#include "../Entities/Bot.h"
#include "../Entities/EndZone.h"
#include "../Entities/DefensePoint.h"
#include "../ResearchProjectGameMode.h"

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
			//float ratio = executee->getExpWorth() / (1.25 * executor->level); //progExecutee->level;
			//ratio = ratio > 1 ? 1 : ratio;
			//result = -ratio * maxInsistEffect;

			//No Effect on EXP
			break;
		}
		case Action_Type::Move_Toward:
		{
			float ratio = executee->getExpWorth() / executor->getRemainingExp();
			result = (ratio <= 1) ? ratio * maxInsistEffect : maxInsistEffect;
			result *= (1 - executor->distanceToEnd / executor->fieldWidth);
			break;
		}
		case Action_Type::Defend_Area:
		{
			//No Effect on EXP
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
			//No Effect on Gold
			break;
		}
		case Action_Type::Move_Toward:
		{
			float ratio = executee->getGoldWorth() / maxGoldGain;
			result = (ratio * (1 - (executor->distanceToEnd-1) / executor->fieldWidth) + 0.25)* maxInsistEffect; //distToEnd-1 so we don't have 1-1=0 for effect
			result = result > maxInsistEffect ? maxInsistEffect : result;
			break;
		}
		case Action_Type::Defend_Area:
		{
			//No Effect on Gold
		}
	}
	return result;
}
float Action::getLiveEffect(ABot * const executor){
	float result = 0;
	switch (action_type){
		case Action_Type::Kill:
		{
			//Some sort of THREAT indicator interface would be a good idea here
			//!!!!!!!!!!!!!!!!! TODO !!!!!!!!!!!!!!!!!!!!!!!!!
			float ratio = executee->getExpWorth() / (1.5 * executor->level); //progExecutee->level;
			ratio = ratio > 1 ? 1 : ratio;
			result = -ratio * maxInsistEffect;
			break; 
		}
		
		case Action_Type::Evade:
		{
			float ratio = executee->getExpWorth() / (1.5 * executor->level); //progExecutee->level;
			ratio = ratio > 1 ? 1 : ratio;
			result = ratio * maxInsistEffect;
			break;
		}
		case Action_Type::Move_Toward:
		{
			//No Effect on Live
			break;
		}
		case Action_Type::Defend_Area:
		{
			//No Effect on Live
		}
	}
	return result;
}
float Action::getDefendEffect(ABot * const executor){
	float result = 0;
	AResearchProjectGameMode *gameMode = (AResearchProjectGameMode*)executor->GetWorld()->GetAuthGameMode();
	float tg1 = gameMode->Team_1_Gold > 0 ? gameMode->Team_1_Gold : 1;
	float tg2 = gameMode->Team_2_Gold > 0 ? gameMode->Team_2_Gold : 1;
	float tgRatio = executor->team == ETeam_Enum::team1 ? tg2 / tg1 : tg1 / tg2;
	tgRatio = tgRatio > maxInsistEffect ? maxInsistEffect : tgRatio;
	switch (action_type){
		case Action_Type::Kill:{
			result = tgRatio * (1 - ((ABot*)executee)->distanceToEnd / ((ABot*)executee)->fieldWidth);
			break;
		}
		case Action_Type::Evade:
		{
			result = -tgRatio/2;
			break;
		}
		case Action_Type::Move_Toward:
		{
			result = (1 - executor->distanceToEnd / executor->fieldWidth) * -tgRatio;;
			break;
		}
		case Action_Type::Defend_Area:
		{
			float danger = executor->team == ETeam_Enum::team1 ? tg2 / gameMode->Gold_To_Win : tg1 / gameMode->Gold_To_Win;
			result = tgRatio * danger;
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
	case Action_Type::Defend_Area:
	{
		executor->runDefendAreaBehavior((ADefensePoint*)executee);
	}
	}
}
