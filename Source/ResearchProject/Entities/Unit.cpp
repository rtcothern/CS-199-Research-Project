// Fill out your copyright notice in the Description page of Project Settings.

#include "ResearchProject.h"
#include "../GOB/Action.h"
#include "Unit.h"


// Sets default values
AUnit::AUnit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	health = 100;
	speed = 1.0;
	attackDamage = 5;
	attackSpeed = 1.25;
	attackRange = 300;
}

// Called when the game starts or when spawned
void AUnit::BeginPlay()
{
	Action *killAction = new Action(Action::Action_Type::Kill, this);
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

