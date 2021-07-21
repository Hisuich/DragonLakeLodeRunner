#pragma once
#include "Spawner.h"
#include "Options.h"

class HeroSpawner : public Spawner
{
protected:
	
	int heroSpawnIndex;
	int playerIndex;
	int heroLife;

private:
	void FindHeroSpawn();
	void SpawnHero();
public:
	HeroSpawner();
	virtual void Process(float deltaTime);
};