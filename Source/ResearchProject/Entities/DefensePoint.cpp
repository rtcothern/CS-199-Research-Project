// Code copyright © Raymond Cothern, 2015

#include "ResearchProject.h"
#include "DefensePoint.h"
#include "../GOB/Action.h"


// Sets default values
ADefensePoint::ADefensePoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADefensePoint::BeginPlay()
{
	Action *defAction = new Action(Action::Action_Type::Defend_Area, this);
	exposedActions.Emplace(defAction);
	Super::BeginPlay();
	
}

