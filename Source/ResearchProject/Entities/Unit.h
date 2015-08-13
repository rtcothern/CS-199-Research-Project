// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "UnitProperties.h"
#include "../GOB/Action.h"
#include "Unit.generated.h"

using namespace UP;

UCLASS()
class RESEARCHPROJECT_API AUnit : public ACharacter
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUnit();

	// Called when the game starts or when Actionwned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit_Team)
	ETeam_Enum teamEnum;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Unit_Stats)
	int32 health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Unit_Stats)
	float speed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Unit_Stats)
	FResource primaryResource;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Unit_Progression)
	int32 exp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Unit_Progression)
	int32 level;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;
	
	//UFUNCTION(BlueprintCallable, Category = Unit_Actions)
	TArray<Action> getExposedActions() { return exposedActions; };

protected:
	TArray<Action> exposedActions;
	uint16 expWorth, goldWorth;
	uint16 effectiveDPS;
};
