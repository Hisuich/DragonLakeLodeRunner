#pragma once

#include <vector>
#include "Spawner.h"

class GameObjects;

class Spawners
{
private:
	GameObjects* gameObjects;
	std::vector<Spawner_sptr> spawners;

public:
	Spawners(GameObjects*);

	void AddSpawner(Spawner_sptr spawner);
	void Process(float delta);
};