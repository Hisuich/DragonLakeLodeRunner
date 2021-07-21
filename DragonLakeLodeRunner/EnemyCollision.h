#pragma once

#include "UnitCollision.h"
#include "Vector2.h"
#include "Vector2Int.h"
#include <unordered_map>

class EnemyCollision : public UnitCollision
{
private:
	bool haveGold;
private:
	void SpawnGold(int index);
public:
	EnemyCollision();
	virtual void CollisionProcess(float delta, int index, int second);
};