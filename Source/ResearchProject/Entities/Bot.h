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

protected:
	class ActionPlanner* planner;
	WorldModel worldModel;
};