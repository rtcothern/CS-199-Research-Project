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
	switch (action_type){
	case Action_Type::Move_Toward:
	case Action_Type::Defend_Area:
		duration = ABot::getAPFrequency() / 60;
		break;
	}
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
	if (executor->level == ABot::MaxLevel)
		return 0;
	switch (action_type){
		case Action_Type::Kill:
		{
			float ratio = executee->getExpWorth() / executor->getRemainingExp() * 1.5 * 
				executor->gameMode->zoneWidth / executor->GetHorizontalDistanceTo((ABot*)executee);
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
			result *= (1 - executor->distanceToEnd / executor->gameMode->fieldWidth);
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
			float gainRatio = executee->getGoldWorth() / maxGoldGain;
			float ratio = gainRatio * 1.5 * executor->gameMode->zoneWidth / executor->GetHorizontalDistanceTo((ABot*)executee);
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
			float distRatio = 1 - (executor->distanceToEnd - 1) / executor->gameMode->fieldWidth;
			if (distRatio > 0.85){
				result = (ratio * 4 * distRatio + 0.25);
			}
			else if (distRatio > 0.6){
				result = (ratio * 2 * distRatio + 0.25);
			}
			else {
				//distToEnd-1 so we don't have 1-1=0 for effect
				result = (ratio * distRatio + 0.25);
			}
			result *= (1 + executor->level / ABot::MaxLevel)*maxInsistEffect;
			break;
		}
		case Action_Type::Defend_Area:
		{
			//No Effect on Gold
		}
	}
	result = result > maxInsistEffect ? maxInsistEffect : result;
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
	switch (action_type){
		case Action_Type::Kill:{
			//TODO Look at this more
			result = tgRatio * (1 - ((ABot*)executee)->distanceToEnd / ((ABot*)executee)->gameMode->fieldWidth);
			result = result > maxInsistEffect ? maxInsistEffect : result;
			break;
		}
		case Action_Type::Evade:
		{
			result = -tgRatio/2;
			result = result < -maxInsistEffect ? -maxInsistEffect : result;
			break;
		}
		case Action_Type::Move_Toward:
		{
			//This is overly discouraging, leads to all defense stalemate
			result = -(1 - executor->distanceToEnd / executor->gameMode->fieldWidth) * tgRatio * 0.75;
			result = result < -maxInsistEffect ? -maxInsistEffect : result;
			break;
		}
		case Action_Type::Defend_Area:
		{
			//Base amount we should be worried about defending
			float danger = executor->team == ETeam_Enum::team1 ? tg2 / gameMode->Gold_To_Win : tg1 / gameMode->Gold_To_Win;

			//Want to discourage turning around when were getting closer. Move toward already takes this into
			//account somewhat but it should be done on this end as well.
			float displacementImpact = 0, distance = 1 - executor->distanceToEnd;
			if (distance > gameMode->fieldWidth / 2){
				float distOverHalf = distance - (gameMode->fieldWidth / 2);

				//For every increment of zoneWidth over the half mark, we want to reduce the impact of defending
				//by maxInsistEffect/numZones
				displacementImpact = distOverHalf / gameMode->zoneWidth * (maxInsistEffect/gameMode->numZones);
			}
			result = tgRatio * danger - displacementImpact;
			result = result > maxInsistEffect ? maxInsistEffect : result;

		}
	}
	return result;
}

void Action::evalDuration(FVector & execLocation, const float & execSpeed){
	FVector executeeLoc = ((ABot*)executee)->GetActorLocation();
	duration = FVector::Dist(executeeLoc, execLocation) / execSpeed / 60;
	execLocation = executeeLoc;
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
		executor->getWorldModel()->applyAction(this, -1);
	}
	}
}
