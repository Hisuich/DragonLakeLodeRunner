#pragma once

#include "Framework.h"
#include <iostream>
#include <vector>

#include "GameObjectType.h"

class GameObjects;

class UnitCollision
{
protected:
	GameObjects* gameObjects;
	GameObjectType collisionType;
	int mask;

public:
	UnitCollision();
	void SetGameObjects(GameObjects*);
	void Collision(float delta, int first, int second);
	bool isCollisionType(GameObjectType type);

protected:
	virtual void CollisionProcess(float delta,int index, int secondIndex) = 0;

	void Solid(float delta, int first, int second);

};

typedef std::shared_ptr<UnitCollision> UnitCollision_sptr;