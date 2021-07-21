#pragma once

#include "Framework.h"
#include "GameManager.h"

#include "Options.h"

#include <memory>
#include <iostream>


class MainFramework : public Framework
{
private:
	float deltaTime;
	float prevTime;
	std::unique_ptr<GameManager> gameManager;

public:

	MainFramework();
	// no function calls are available here, this function should only return width, height and fullscreen values
	virtual void PreInit(int& width, int& height, bool& fullscreen);

	// return : true - ok, false - failed, application will exit
	virtual bool Init();

	virtual void Close();

	// return value: if true will exit the application
	virtual bool Tick();

	// param: xrel, yrel: The relative motion in the X/Y direction 
	// param: x, y : coordinate, relative to window
	virtual void onMouseMove(int x, int y, int xrelative, int yrelative);

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);

	virtual void onKeyPressed(FRKey k);

	virtual void onKeyReleased(FRKey k);

	virtual const char* GetTitle();
};