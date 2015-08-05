// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Unit.generated.h"


UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class ETeam_Enum : uint8
{
	team1 	UMETA(DisplayName = "team1"),
	team2 	UMETA(DisplayName = "team2"),
	teamNone	UMETA(DisplayName = "teamNone")
};

USTRUCT()
struct RESEARCHPROJECT_API FResource{
	GENERATED_BODY()
	uint32 amount;
	uint32 maxAmount;
	enum class Type	{
		MANA,
		OTHER
	} type;
	uint32 regenRate;
};
UCLASS()
class RESEARCHPROJECT_API AUnit : public ACharacter
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUnit();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Team)
	ETeam_Enum teamEnum;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Stats)
	int32 health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Stats)
	float speed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Stats)
	FResource primaryResource;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Progression)
	int32 exp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Progression)
	int32 level;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

};
