#include "Controllers.h"

Controllers::Controllers(GameObjects* gameObjects)
{
	this->gameObjects = gameObjects;
}

void Controllers::AddController(UnitController_sptr controller)
{
	controller->SetGameObjects(gameObjects);
	controllers.push_back(controller);
}

void Controllers::Process(float delta)
{
	for (int i = 0; i < controllers.size(); i++)
	{
		controllers[i]->Process(delta);
	}
}

void Controllers::onMouseMove(int x, int y, int xrelative, int yrelative)
{
	for (int i = 0; i < controllers.size(); i++)
	{
		controllers[i]->onMouseMove(x,y,xrelative,yrelative);
	}
}

void Controllers::onMouseButtonClick(FRMouseButton button, bool isReleased)
{
	for (int i = 0; i < controllers.size(); i++)
	{
		controllers[i]->onMouseButtonClick(button,isReleased);
	}
}

void Controllers::onKeyPressed(FRKey k)
{
	for (int i = 0; i < controllers.size(); i++)
	{
		controllers[i]->onKeyPressed(k);
	}
}

void Controllers::onKeyReleased(FRKey k)
{
	for (int i = 0; i < controllers.size(); i++)
	{
		controllers[i]->onKeyReleased(k);
	}
}
