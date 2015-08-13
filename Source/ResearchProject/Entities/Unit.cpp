// Fill out your copyright notice in the Description page of Project Settings.

#include "ResearchProject.h"
#include "../GOB/Action.h"
#include "../GOB/Action_Kill.h"
#include "Unit.h"


// Sets default values
AUnit::AUnit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	health = 100;
	primaryResource.type = FResource::Type::MANA;
	primaryResource.amount = 0;
	primaryResource.maxAmount = 100;
	primaryResource.regenRate = 2;
	speed = 1.0;
	exp = 0;
	level = 1;

}

// Called when the game starts or when spawned
void AUnit::BeginPlay()
{
	Action_Kill killAction = Action_Kill(expWorth, goldWorth);
	exposedActions.Emplace(killAction);
	Super::BeginPlay();
}

// Called every frame
void AUnit::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );

}

float AUnit::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser){
	health -= DamageAmount;
	return health;
}

