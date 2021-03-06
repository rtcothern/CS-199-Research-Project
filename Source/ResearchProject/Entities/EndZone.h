// Code copyright © Raymond Cothern, 2015

#pragma once

#include "GOB/GobObject.h"
#include "GameFramework/Actor.h"
#include "EndZone.generated.h"

/**
 * 
 */
UCLASS()
class RESEARCHPROJECT_API AEndZone : public AActor, public GobObject
{
	GENERATED_BODY()
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	
	
	uint16 expWorth = 0;
	uint16 goldWorth = 15;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit_Stats)
	ETeam_Enum team;

	uint16 getExpWorth() { return expWorth; };
	uint16 getGoldWorth() { return goldWorth; };

	UFUNCTION(BlueprintCallable, Category = Unit_Progression)
		int32 getGoldWorthBP(){ return (int32)getGoldWorth(); };
	UFUNCTION(BlueprintCallable, Category = Unit_Progression)
		int32 getExpWorthBP(){ return (int32)getExpWorth(); };
};
