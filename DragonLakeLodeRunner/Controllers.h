#pragma once

#include "Framework.h"
#include <memory>
#include <iostream>
#include "UnitController.h"		
#include <vector>

class GameObjects;

using std::vector;

class Controllers
{
	protected:
		GameObjects* gameObjects;
		vector<UnitController_sptr> controllers;

	public:
		Controllers(GameObjects*);

		void AddController(UnitController_sptr controller);

		virtual void Process(float delta);

		virtual void onMouseMove(int x, int y, int xrelative, int yrelative);

		virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);

		virtual void onKeyPressed(FRKey k);

		virtual void onKeyReleased(FRKey k);
};