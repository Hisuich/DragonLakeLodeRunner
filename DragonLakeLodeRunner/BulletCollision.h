#pragma once

#include "UnitCollision.h"

class BulletCollision : public UnitCollision
{
public:
	BulletCollision();
	virtual void CollisionProcess(float delta, int index, int second);

};