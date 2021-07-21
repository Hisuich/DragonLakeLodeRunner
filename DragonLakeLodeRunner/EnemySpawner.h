#pragma once

#include "Spawner.h"
#include <vector>
#include <math.h>

class EnemySpawner : public Spawner
{
protected:
	std::vector<int> enemiesIndex;
	std::vector<int> enemySpawnsIndex;

private:
	void FindEnemySpawns();
	void FindEnemies();
	void SpawnEnemies();

public:
	EnemySpawner();
	virtual void Process(float deltaTime);
};