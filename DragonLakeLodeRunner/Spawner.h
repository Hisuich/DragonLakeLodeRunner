#pragma once
#include <iostream>
#include <memory>

class GameObjects;

class Spawner
{
protected:
	GameObjects* gameObjects;

public:
	Spawner();
	virtual void Process(float delta) = 0;
	virtual void SetGameObjects(GameObjects*);
};

typedef std::shared_ptr<Spawner> Spawner_sptr;