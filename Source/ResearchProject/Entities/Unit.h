// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "../GOB/Action.h"
#include "../GOB/GobObject.h"
#include "Unit.generated.h"

UCLASS()
class RESEARCHPROJECT_API AUnit : public ACharacter, public GobObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUnit();
	virtual ~AUnit() {};
	// Called when the game starts or when Actionwned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Unit_Properties)
	int32 health;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Unit_Properties)
	float speed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Unit_Properties)
	int32 attackDamage;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Unit_Properties)
	float attackSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Unit_Properties)
	float attackRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit_Properties)
	ETeam_Enum team;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit_Properties)
	bool alive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit_Properties)
	class AEndZone* friendlyEndZone;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;
	
	UFUNCTION(BlueprintCallable, Category = Unit_Progression)
	int32 getGoldKillWorthBP(){ return (int32)getGoldWorth(); };
	UFUNCTION(BlueprintCallable, Category = Unit_Progression)
	int32 getExpKillWorthBP(){ return (int32)getExpWorth(); };

	
};
