// Code copyright © Raymond Cothern, 2015

#pragma once
class Action;
class ABot;

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
	Goal(Goal_Type type, ABot *ownerBot);

	Goal_Type goal_type;

	virtual float getDC() const;

	float getPassiveChange() const { return changePerMinute; };

	float getInsistence() const { return insistence; };

	virtual void applyAction(Action *action);

	void update(float deltaTime);

protected:
	ABot *owner;
	const float maxInsistence = 10;
	float insistence, changePerMinute;
	bool bEnabled;
};