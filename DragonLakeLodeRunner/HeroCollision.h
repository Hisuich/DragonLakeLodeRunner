#pragma once

#include "UnitCollision.h"
#include "Vector2.h"
#include "Vector2Int.h"
#include "Options.h"

class HeroCollision : public UnitCollision
{
public:
	HeroCollision();
	virtual void CollisionProcess(float delta, int index, int second);
};