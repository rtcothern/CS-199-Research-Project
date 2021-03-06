// Code copyright © Raymond Cothern, 2015

#pragma once

#include "GameFramework/Actor.h"
#include "../GOB/GobObject.h"
#include "DefensePoint.generated.h"

UCLASS()
class RESEARCHPROJECT_API ADefensePoint : public AActor, public GobObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADefensePoint();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit_Stats)
		ETeam_Enum team;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
};
