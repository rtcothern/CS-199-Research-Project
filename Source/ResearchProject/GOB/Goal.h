// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <string>

#define String std::string
class RESEARCHPROJECT_API Goal
{
	
public:	
	// Sets default values for this actor's properties
	Goal(String name);
	Goal(String name, int32 insist);
	Goal(){ id = highestId++; };
	~Goal(){};

	int32 getDC();
	int32 getDCFromNewInsist(int32 newVal);
	int32 getPassiveChange();
	int32 getId();

	//void setInsistence(int32 newIns){ insistence = newIns; };
	void modifyInsistence(int32 delta){ insistence += delta; };

protected:
	int32 insistence;
	int32 changePerMinute;
	int32 id;
	static int32 highestId;
	String name;
};
