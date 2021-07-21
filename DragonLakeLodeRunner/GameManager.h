#pragma once

#include "Framework.h"
#include "GameState.h"
#include "Map.h"
#include "MapHelper.h"

#include <iostream>
#include <memory>
#include <vector>

class GameManager
{
private:
	GameState state;
	std::vector<Map> maps;
	int currentMap;

public:
	GameManager();
	GameState GetGameState();

	void Update(float deltaTime);
	void Draw();

	void onMouseMove(int x, int y, int xrelative, int yrelative);

	void onMouseButtonClick(FRMouseButton button, bool isReleased);

	void onKeyPressed(FRKey k);

	void onKeyReleased(FRKey k);

};