#pragma once

#include "UnitController.h"
#include "Vector2.h"
#include <vector>
#include "Options.h"

class EnemyController : public UnitController
{
protected:

	std::vector<int> enemiesIndex;
	int speed;

private:
	void EnemyControl(int index, Vector2 playerPos);
	Vector2 FindLadder(int index);

public:
	EnemyController();

	virtual void Process(float delta);

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative);

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);

	virtual void onKeyPressed(FRKey k);

	virtual void onKeyReleased(FRKey k);
};