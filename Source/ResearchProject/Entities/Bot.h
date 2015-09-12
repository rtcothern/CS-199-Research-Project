// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Unit.h"
#include "../GOB/WorldModel.h"
#include "Bot.generated.h"

using namespace UP;

UCLASS()
class RESEARCHPROJECT_API ABot : public AUnit
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABot();
	~ABot();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UFUNCTION(BlueprintCallable, Category = Unit_Actions)
		void executeNextAction();

	UFUNCTION(BlueprintNativeEvent, Category = Unit_Behavior)
		void runAttackBehavior(AUnit* target);
	UFUNCTION(BlueprintNativeEvent, Category = Unit_Behavior)
		void runMoveTowardBehavior(AEndZone* moveTarget);

	UFUNCTION(BlueprintCallable, Category = Unit_Scoring)
		void scoreKill(ABot* victim);
	UFUNCTION(BlueprintCallable, Category = Unit_Scoring)
		void scoreEndZone(AEndZone* enemyEndZone);

	UFUNCTION(BlueprintCallable, Category = Unit_Management)
		void Die();
	UFUNCTION(BlueprintCallable, Category = Unit_Management)
		void Respawn();
	UFUNCTION(BlueprintCallable, Category = Unit_Management)
		float getExpInsist();
	UFUNCTION(BlueprintCallable, Category = Unit_Management)
		float getGoldInsist();


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Unit_Stats)
	float distanceToEnd;

	UPROPERTY(BlueprintReadOnly, Category = Unit_Stats)
		int32 exp;
	UPROPERTY(BlueprintReadOnly, Category = Unit_Stats)
		int32 level;
	UPROPERTY(BlueprintReadOnly, Category = Unit_Stats)
		int32 goldEarned;

	const uint16 baseGoldWorth = 3;
	const float numZones = 8;
	const float fieldWidth = 4000;
	const float zoneWidth = fieldWidth / numZones;
	const float aggroRange = 1000;

	void acquireExp(uint8 exp);

	uint16 getRemainingExp();
	uint16 getExpForNextLevel();

	//Overridden functions
	uint16 getExpWorth() override;
	uint16 getGoldWorth() override;

protected:
	class ActionPlanner* planner;
	WorldModel worldModel;

private:
	float apTimer, apFrequency;
};