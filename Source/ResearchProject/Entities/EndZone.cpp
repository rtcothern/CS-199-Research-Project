// Code copyright © Raymond Cothern, 2015

#include "ResearchProject.h"
#include "EndZone.h"
#include "GOB/Action.h"

// Called when the game starts or when spawned
void AEndZone::BeginPlay()
{
	Action *killAction = new Action(Action::Action_Type::Move_Toward, this);
	exposedActions.Emplace(killAction);
	Super::BeginPlay();
}


