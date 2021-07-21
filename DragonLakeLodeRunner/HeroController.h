#pragma once

#include "UnitController.h"
#include "Vector2.h"

class HeroController : public UnitController
{
protected:
	
	int playerIndex;
	int speed;

	Vector2 mousePosition;
	
private:
	Vector2 FindFloorPosition(bool left);
	void SpawnBullet(bool left);

public:
	HeroController();

	virtual void Process(float delta);

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative);

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);

	virtual void onKeyPressed(FRKey k);

	virtual void onKeyReleased(FRKey k);
};