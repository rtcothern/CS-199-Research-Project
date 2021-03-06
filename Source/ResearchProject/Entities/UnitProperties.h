// Code copyright © Raymond Cothern, 2015

#pragma once

//#include "Components/ActorComponent.h"
//#include "UnitProperties.generated.h"

struct RESEARCHPROJECT_API FResource{
	uint32 amount;
	uint32 maxAmount;
	enum class Type	{
		MANA,
		OTHER
	} type;
	float regenRate;
};

//class RESEARCHPROJECT_API FProgression{
//public:
//	virtual uint16 getExpKillWorth() = 0;
//	virtual uint16 getGoldKillWorth() = 0;
//	virtual void Tick(float deltaTime) = 0;
//};

//struct RESEARCHPROJECT_API FParagonProgression : public FProgression{
//	uint16 exp;
//	uint8 level;
//	float distanceToEnd;
//
//	const uint16 baseGoldWorth = 5;
//	const float numZones = 8;
//	const float fieldWidth = 4000;
//	const float zoneWidth = fieldWidth / numZones;
//
//	FParagonProgression();
//	uint16 getRemainingExp();
//	uint16 getExpForNextLevel();
//	uint16 getExpKillWorth();
//	uint16 getGoldKillWorth();
//	void Tick(float deltaTime);
//};
//struct RESEARCHPROJECT_API FCreepProgression : public FProgression{
//	const float increasePerMinute = 0.2;
//	uint16 expWorth;
//	uint16 goldWorth;
//
//	FCreepProgression();
//	uint16 getExpKillWorth();
//	uint16 getGoldKillWorth();
//	void Tick(float deltaTime);
//};

//struct RESEARCHPROJECT_API FEZProgression : public FProgression{
//	uint16 expWorth = 0;
//	uint16 goldWorth = 15;
//
//	uint16 getExpKillWorth(){ return expWorth; };
//	uint16 getGoldKillWorth(){ return goldWorth; };
//	void Tick(float deltaTime){};
//};


//UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
//class RESEARCHPROJECT_API UUnitProperties : public UActorComponent
//{
//	GENERATED_BODY()
//
//public:	
//	ETeam_Enum team;
//	FResource primaryResource;
//	FProgression *progression;
//
//	// Sets default values for this component's properties
//	UUnitProperties();
//
//	// Called when the game starts
//	virtual void BeginPlay() override;
//	
//	// Called every frame
//	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
//	
//};
