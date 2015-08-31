#include "ResearchProject.h"
#include "Goal_Exp.h"
#include "Action_Kill.h"
#include "../Entities/Bot.h"

Action_Kill::Action_Kill(float expGain, float goldGain, AUnit *target) : Action()
{
	this->expGain = expGain;
	this->goldGain = goldGain;
	this->target = target;
}
Action_Kill::~Action_Kill()
{
}

float Action_Kill::getExpEffect(float expNeededForLevel) {
	float ratio = expGain / expNeededForLevel;
	return -ratio;
};
float Action_Kill::getGoldEffect(float currentGold) {
	float ratio = goldGain / currentGold;
	return -ratio;
};
//float Action_Kill::getLiveEffect(const Goal* goal) {
//
//};
//float Action_Kill::getPushEffect(const Goal* goal) {
//
//};
void Action_Kill::executeAction(ABot *executor){
	executor->runAttackBehavior(target);
}
