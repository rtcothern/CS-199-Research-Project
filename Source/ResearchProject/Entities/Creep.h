// Code copyright © Raymond Cothern, 2015

#pragma once

#include "Entities/Unit.h"
#include "Creep.generated.h"

/**
 * 
 */
UCLASS()
class RESEARCHPROJECT_API ACreep : public AUnit
{
	GENERATED_BODY()
public:
	ACreep();
	virtual void BeginPlay() override;
};
