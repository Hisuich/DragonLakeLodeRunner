#pragma once

#include "UnitController.h"
#include <vector>

class DestructFloorController : public UnitController
{
private:
	const float restoreTime = 3.0f;

	std::vector<bool> destructed;
	std::vector<float> timers;
	std::vector<int> floorIndexes;

private:
	void FindFloor();
	void CheckFloor();
	void CheckDestruct(float delta);
	void Destroy(int index);
	void Restore(int index);

public:
	DestructFloorController();

	virtual void Process(float delta);

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative);

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);

	virtual void onKeyPressed(FRKey k);

	virtual void onKeyReleased(FRKey k);
};
