#pragma once

#include "Framework.h"

#include <iostream>

#include "UnitCollision.h"

#include <vector>

class GameObjects;

using std::vector;

class Collisions
{
private:
	GameObjects* gameObjects;
	vector<UnitCollision_sptr> collisions;
	float mask;

public:
	Collisions(GameObjects*);
	void AddCollision(UnitCollision_sptr collision);
	void Process(float delta);
	void Collision(float delta, int first, int second);
};