#include "Map.h"

Map::Map()
{
	gameObjects = new GameObjects();
	background = createSprite("data/background.png");
	Init();
}

Map::~Map()
{
}

void Map::Init()
{
	gameObjects->collisions->AddCollision(std::make_shared<HeroCollision>());
	gameObjects->collisions->AddCollision(std::make_shared<EnemyCollision>());
	gameObjects->collisions->AddCollision(std::make_shared<BulletCollision>());

	gameObjects->controllers->AddController(std::make_shared<HeroController>());
	gameObjects->controllers->AddController(std::make_shared<EnemyController>());
	gameObjects->controllers->AddController(std::make_shared<DestructFloorController>());

	gameObjects->spawners->AddSpawner(std::make_shared<HeroSpawner>());
	gameObjects->spawners->AddSpawner(std::make_shared<EnemySpawner>());
}

void Map::Update(float deltaTime)
{
	gameObjects->Update(deltaTime);
}

void Map::Draw()
{
	drawSprite(background, 0, 0);
	gameObjects->Draw();
}

void Map::onMouseMove(int x, int y, int xrelative, int yrelative)
{
	gameObjects->onMouseMove(x, y, xrelative, yrelative);
}


void Map::onMouseButtonClick(FRMouseButton button, bool isReleased)
{
	gameObjects->onMouseButtonClick(button, isReleased);
}

void Map::onKeyPressed(FRKey k)
{
	gameObjects->onKeyPressed(k);
}

void Map::onKeyReleased(FRKey k)
{
	gameObjects->onKeyReleased(k);
}
	