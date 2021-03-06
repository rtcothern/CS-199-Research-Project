// Code copyright © Raymond Cothern, 2015

#pragma once
#include "AutomationTest.h"
#include "ResearchProject.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(ActionPlannerTest, "MyCoolTest")

class ActionPlannerTest : FAutomationTestBase
{
public:
	ActionPlannerTest();
	~ActionPlannerTest();

	virtual bool RunTest(const FString& Parameters) override;
};
