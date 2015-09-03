// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "UnitProperties.h"
#include "../GOB/Action.h"
#include "Unit.generated.h"

UCLASS()
class RESEARCHPROJECT_API AUnit : public ACharacter
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUnit();
	virtual ~AUnit() { delete progression; };
	// Called when the game starts or when Actionwned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Unit_Stats)
	int32 health;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Unit_Stats)
	float speed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Unit_Stats)
	int32 attackDamage;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Unit_Stats)
	float attackSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Unit_Stats)
	float attackRange;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Unit_Stats)
	ETeam_Enum team;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;
	
	TArray<Action*> getExposedActions() { return exposedActions; };

	UFUNCTION(BlueprintCallable, Category = Unit_Progression)
		int32 getGoldWorth() { return progression->getGoldKillWorth(); };
	UFUNCTION(BlueprintCallable, Category = Unit_Progression)
		int32 getExpWorth(){ return progression->getExpKillWorth(); };

	//UFUNCTION(BlueprintNativeEvent, Category = Unit_Executions)
	//	void attackTarget(AUnit* target);

	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Unit_Stats)
	FProgression* progression;

	

protected:
	TArray<Action*> exposedActions;
	uint16 effectiveDPS;
};
