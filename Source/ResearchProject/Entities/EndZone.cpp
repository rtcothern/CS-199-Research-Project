// Code copyright © Raymond Cothern, 2015

#include "ResearchProject.h"
#include "EndZone.h"

// Called when the game starts or when spawned
void AEndZone::BeginPlay()
{
	progression = new FEZProgression();
	Super::BeginPlay();
}


