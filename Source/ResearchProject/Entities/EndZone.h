// Code copyright © Raymond Cothern, 2015

#pragma once

#include "Entities/Unit.h"
#include "EndZone.generated.h"

/**
 * 
 */
UCLASS()
class RESEARCHPROJECT_API AEndZone : public AUnit
{
	GENERATED_BODY()
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	
	
};
