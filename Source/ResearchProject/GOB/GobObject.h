// Code copyright © Raymond Cothern, 2015

#pragma once
class Action;
/**
 * 
 */
UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class ETeam_Enum : uint8
{
	team1 	UMETA(DisplayName = "team1"),
	team2 	UMETA(DisplayName = "team2"),
	teamNone	UMETA(DisplayName = "teamNone")
};

class RESEARCHPROJECT_API GobObject
{
public:
	GobObject();
	~GobObject();

	virtual uint16 getExpWorth() { return 0; };
	virtual uint16 getGoldWorth() { return 0; };

	TArray<Action*> getExposedActions() { return exposedActions; };
protected:
	TArray<Action*> exposedActions;
};
