#pragma once

#include "Framework.h"
#include "GameObjectType.h"
#include <memory>
#include <iostream>

class GameObjects;

class UnitController
{
protected:
	GameObjects* gameObjects;
	GameObjectType type;

public:
	UnitController();
	void SetGameObjects(GameObjects* gameObjects);

	virtual void Process(float delta)=0;

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative)=0;

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased)=0;

	virtual void onKeyPressed(FRKey k)=0;

	virtual void onKeyReleased(FRKey k)=0;
};

typedef std::shared_ptr<UnitController> UnitController_sptr;