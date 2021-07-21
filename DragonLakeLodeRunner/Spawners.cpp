#include "Spawners.h"

Spawners::Spawners(GameObjects* gameObjects)
{
	this->gameObjects = gameObjects;
	spawners = std::vector<Spawner_sptr>();

}

void Spawners::AddSpawner(Spawner_sptr spawner)
{
	spawner->SetGameObjects(gameObjects);
	spawners.push_back(spawner);
}

void Spawners::Process(float delta)
{
	for (int i = 0; i < spawners.size(); i++)
	{
		spawners[i]->Process(delta);
	}
}
