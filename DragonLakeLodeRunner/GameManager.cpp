#include "GameManager.h"

GameManager::GameManager()
{
	maps = vector<Map>();
	MapHelper mapHelper = MapHelper();
	Map map = mapHelper.GetHardcodeMap();
	maps.push_back(map);
	currentMap = 0;
	state = GameState::Idle;
}

GameState GameManager::GetGameState()
{
	return GameState::Idle;
}

void GameManager::Update(float deltaTime)
{
	maps[currentMap].Update(deltaTime);
}

void GameManager::Draw()
{
	drawTestBackground();

	maps[currentMap].Draw();
}

void GameManager::onMouseMove(int x, int y, int xrelative, int yrelative)
{
	maps[currentMap].onMouseMove(x, y, xrelative, yrelative);
}

void GameManager::onMouseButtonClick(FRMouseButton button, bool isReleased)
{
	maps[currentMap].onMouseButtonClick(button, isReleased);
}

void GameManager::onKeyPressed(FRKey k)
{
	maps[currentMap].onKeyPressed(k);
}

void GameManager::onKeyReleased(FRKey k)
{
	maps[currentMap].onKeyReleased(k);
}
