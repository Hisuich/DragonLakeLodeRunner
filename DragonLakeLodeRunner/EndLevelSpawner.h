#pragma once
#include "Spawner.h"

class EndLevelSpawner : Spawner
{
protected:
	int endLevelIndex;
	bool exitSpawned;

private:
	void FindEndLevel();
	void SpawnEndLevel();

public:
	EndLevelSpawner();
	virtual void Process(float delta);
};