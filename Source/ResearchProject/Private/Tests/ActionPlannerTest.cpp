// Code copyright © Raymond Cothern, 2015

#include "ResearchProject.h"
#include "AutomationTest.h"
#include "../../GOB/Goal.h"
#include "../../GOB/Action.h"
#include "../../GOB/WorldModel.h"
#include "../../GOB/ActionPlanner.h"

using namespace std;

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FActionPlannerTest, "AIUnitTests", EAutomationTestFlags::ATF_SmokeTest)

bool FActionPlannerTest::RunTest(const FString& Parameters)
{
	vector<Goal> testGoals;
	vector<Action> testActions;
	testGoals.push_back(Goal(TEXT("Eat"), 4));
	testGoals.push_back(Goal(TEXT("Bathroom"), 3));
	testActions.push_back(Action(TEXT("Drink-Soda"), 0));
	testActions.push_back(Action(TEXT("Visit-Bathroom"), 0));
	testActions[0].addGoalEffect(testGoals[0].getId(), -2);
	testActions[0].addGoalEffect(testGoals[1].getId(), 2);
	testActions[1].addGoalEffect(testGoals[1].getId(), -3);

	WorldModel world(testActions, testGoals);
	ActionPlanner planner;
	Action a = planner.planAction(world, 1);
	
	/*AddError(FString::Printf(TEXT("The testing goat asdfasdfasdfding! ")));*/

	return true;
}