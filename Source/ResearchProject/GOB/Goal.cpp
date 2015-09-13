 // Code copyright © Raymond Cothern, 2015

#include "ResearchProject.h"
#include "Action.h"
#include "Goal.h"
#include "Entities/Bot.h"
#include "../ResearchProjectGameMode.h"

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
		result = 1.5*insistence*insistence;
		break;
	case Goal_Type::Exp:
		result = insistence*insistence;
		break;
	case Goal_Type::Live:
		result = insistence*insistence*insistence;
		break;
	case Goal_Type::Defend:
		result = 2.5*insistence*insistence;
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

void Goal::update(float deltaTime){
	AResearchProjectGameMode *gameMode = (AResearchProjectGameMode*)owner->GetWorld()->GetAuthGameMode();
	float teamGold = 0, enemyTeamGold = 0;
	switch (owner->team){
		case ETeam_Enum::team1:
			teamGold = gameMode->Team_1_Gold;
			enemyTeamGold = gameMode->Team_2_Gold;
			break;
		case ETeam_Enum::team2:
			teamGold = gameMode->Team_2_Gold;
			enemyTeamGold = gameMode->Team_1_Gold;
			break;
	}
	float maxGold = gameMode->Gold_To_Win;

	switch (goal_type)
	{
		case Goal_Type::Gold:{
			teamGold = teamGold == 0 ? 1 : teamGold; //Only relevant when team gold is 0 to avoid div by 0 error
			changePerMinute = enemyTeamGold / teamGold * (teamGold / maxGold + 1);
			break;
		}
		case Goal_Type::Exp:{
			changePerMinute = gameMode->avgLevel / owner->level;
			break;
		}
		case Goal_Type::Live:
			changePerMinute = enemyTeamGold / maxGold * maxInsistence/3;
			break;
		case Goal_Type::Defend:{
			changePerMinute = enemyTeamGold / maxGold * maxInsistence;
			break;
		}
	}
	insistence += changePerMinute * deltaTime / 60;
}