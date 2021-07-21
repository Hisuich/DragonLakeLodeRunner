#include "MainFramework.h"

MainFramework::MainFramework()
{
	deltaTime = 0;
	prevTime = 0;
}

void MainFramework::PreInit(int& width, int& height, bool& fullscreen)
{
	width = Options::options.at("screenWidth");
	height = Options::options.at("screenHeight");
	fullscreen = false;
}

bool MainFramework::Init()
{
	prevTime = (getTickCount() / 1000.0f);

	gameManager = std::make_unique<GameManager>();
	return true;
}

void MainFramework::Close()
{
}

bool MainFramework::Tick()
{
	deltaTime = (getTickCount() / 1000.0f) - prevTime;
	prevTime = (getTickCount() / 1000.0f);

	gameManager->Update(deltaTime);

	gameManager->Draw();

	if (gameManager->GetGameState()	== GameState::End)
		return true;
	
	return false;
}

void MainFramework::onMouseMove(int x, int y, int xrelative, int yrelative)
{
	gameManager->onMouseMove(x,y,xrelative,yrelative);
}

void MainFramework::onMouseButtonClick(FRMouseButton button, bool isReleased)
{
	gameManager->onMouseButtonClick(button, isReleased);
}

void MainFramework::onKeyPressed(FRKey k)
{
	gameManager->onKeyPressed(k);
}

void MainFramework::onKeyReleased(FRKey k)
{
	gameManager->onKeyReleased(k);
}

const char* MainFramework::GetTitle()
{
	return "Lode Runner";
}
