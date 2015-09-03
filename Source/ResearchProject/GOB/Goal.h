// Code copyright © Raymond Cothern, 2015

#pragma once
class Action;
class AUnit;

class RESEARCHPROJECT_API Goal
{
	
public:	
	enum class Goal_Type{
		Gold,
		Exp,
		Live,
		Defend
	};

	~Goal(){};
	Goal();
	Goal(Goal_Type type, AUnit *ownerUnit);

	Goal_Type goal_type;

	virtual float getDC() const;

	float getPassiveChange() const { return changePerMinute; };

	float getInsistence() const { return insistence; };

	virtual void applyAction(Action *action);

protected:
	AUnit *owner;
	const float maxInsistence = 10;
	float insistence, changePerMinute;
	bool bEnabled;
};