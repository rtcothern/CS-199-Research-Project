// Code copyright © Raymond Cothern, 2015

#include "ResearchProject.h"
#include "UnitProperties.h"


//// Sets default values for this component's properties
//UUnitProperties::UUnitProperties()
//{
//	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
//	// off to improve performance if you don't need them.
//	bWantsBeginPlay = true;
//	PrimaryComponentTick.bCanEverTick = true;
//
//	// ...
//}
//
//
//// Called when the game starts
//void UUnitProperties::BeginPlay()
//{
//	Super::BeginPlay();
//
//	// ...
//	
//}
//
//
//// Called every frame
//void UUnitProperties::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
//{
//	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
//
//	// ...
//}



//----------------------------------------------------------------
//	Paragon
//----------------------------------------------------------------
//FParagonProgression::FParagonProgression(){
//	exp = 0;
//	level = 1;
//}
//
//uint16 FParagonProgression::getExpForNextLevel(){
//	return level;
//}
//uint16 FParagonProgression::getRemainingExp(){
//	return getExpForNextLevel() - exp;
//}
//uint16 FParagonProgression::getExpKillWorth(){
//	return getExpForNextLevel();
//}
//uint16 FParagonProgression::getGoldKillWorth(){
//	return baseGoldWorth + (distanceToEnd / zoneWidth - 0.5);
//}
//void FParagonProgression::Tick(float deltaTime){
//	if (exp >= level){
//		exp -= level++;
//	}
//}
//
////----------------------------------------------------------------
//// Creep
////----------------------------------------------------------------
//FCreepProgression::FCreepProgression(){
//	expWorth = 40;
//	goldWorth = 20;
//}
//uint16 FCreepProgression::getExpKillWorth(){
//	return expWorth;
//}
//uint16 FCreepProgression::getGoldKillWorth(){
//	return goldWorth;
//}
//void FCreepProgression::Tick(float deltaTime){
//	goldWorth += deltaTime * increasePerMinute / 60;
//}

