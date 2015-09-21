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
	UFUNCTION(BlueprintNativeEvent, Category = Unit_Behavior)
		void runDefendAreaBehavior(class ADefensePoint* dPoint);
	UFUNCTION(BlueprintNativeEvent, Category = Unit_Behavior)
		void runNoBehavior();

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
	UFUNCTION(BlueprintCallable, Category = Unit_Management)
		float getLiveInsist();
	UFUNCTION(BlueprintCallable, Category = Unit_Management)
		float getDefendInsist();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Unit_Stats)
	float distanceToEnd;

	UPROPERTY(BlueprintReadOnly, Category = Unit_Stats)
		int32 exp;
	UPROPERTY(BlueprintReadOnly, Category = Unit_Stats)
		int32 level;
	UPROPERTY(BlueprintReadOnly, Category = Unit_Stats)
		int32 goldEarned;

	const uint16 baseGoldWorth = 1;
	const float aggroRange = 1000;
	const static uint8 MaxLevel = 10;

	void acquireExp(uint8 exp);

	uint16 getRemainingExp();
	uint16 getExpForNextLevel();
	float getSpeed(){ return this->GetCharacterMovement()->MaxWalkSpeed; };

	//Overridden functions
	uint16 getExpWorth() override;
	uint16 getGoldWorth() override;

	static float getAPFrequency() { return apFrequency; };

	WorldModel* getWorldModel(){ return &worldModel; };

	class AResearchProjectGameMode *gameMode;

protected:
	class ActionPlanner* planner;
	WorldModel worldModel;
private:
	void Score(Action* scoringAction, uint16 goldWorth, uint16 expWorth);
	float apTimer;
	const static float apFrequency;
};