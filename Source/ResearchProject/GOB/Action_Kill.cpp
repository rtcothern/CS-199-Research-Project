#include "ResearchProject.h"
#include "Goal_Exp.h"
#include "Action_Kill.h"
#include "Constants.h"


Action_Kill::Action_Kill(uint16 expGain, uint16 goldGain) : Action()
{
	this->expGain = expGain;
	this->goldGain = goldGain;
}
Action_Kill::~Action_Kill()
{
}

float Action_Kill::getExpEffect(uint16 currentExp) {
	float result = 0;
	float ratio = expGain / currentExp;
	result = ratio * CONSTANTS::MAX_INSISTENCE;
	return -result;
};
float Action_Kill::getGoldEffect(uint16 currentGold) {
	float result = 0;
	float ratio = goldGain / currentGold;
	result = ratio * CONSTANTS::MAX_INSISTENCE;
	return -result;
};
//float Action_Kill::getLiveEffect(const Goal* goal) {
//
//};
//float Action_Kill::getPushEffect(const Goal* goal) {
//
//};
