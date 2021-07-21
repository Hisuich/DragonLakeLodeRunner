#include "MapHelper.h"

void MapHelper::AddGameObjectByMapIndex(GameObjects* gameObjects, int index, Vector2 position)
{
	if (index == 1)
	{
		gameObjects->AddGameObject(position, createSprite("data/floor.png"), GameObjectType::DestructableFloor, GameObjectState::Object);
	}

	if (index == 2)
	{
		gameObjects->AddGameObject(position, createSprite("data/empty.png"), GameObjectType::HeroSpawnPoint, GameObjectState::Object);
	}

	if (index == 3)
	{
		gameObjects->AddGameObject(position, createSprite("data/empty.png"), GameObjectType::EnemySpawnPoint, GameObjectState::Object);
	}
	
	if (index == 4)
	{
		gameObjects->AddGameObject(position, createSprite("data/ladder.png"), GameObjectType::Ladder, GameObjectState::Object);
	}

	if (index == 5)
	{
		gameObjects->AddGameObject(position, createSprite("data/floor.png"), GameObjectType::Wall, GameObjectState::Object);
	}
	if (index == 6)
	{
		gameObjects->AddGameObject(position, createSprite("data/gold.png"), GameObjectType::Gold, GameObjectState::Object);
	}
}

Map MapHelper::GetHardcodeMap()
{
	int mapTiles[16][16] = {
		{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
		{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
		{5,0,4,0,6,3,6,0,0,0,0,0,0,0,0,5},
		{5,0,4,1,1,1,1,1,0,0,0,0,0,0,0,5},
		{5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,5},
		{5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,5},
		{5,0,4,0,6,0,0,6,3,0,4,0,0,0,0,5},
		{5,0,1,1,1,1,1,1,1,1,4,0,0,0,0,5},
		{5,0,0,0,0,0,0,0,0,0,4,0,0,0,0,5},
		{5,0,0,0,0,0,0,0,0,0,4,0,0,0,0,5},
		{5,0,0,0,0,0,0,0,0,0,4,0,0,0,0,5},
		{5,0,0,0,4,0,0,0,0,0,4,0,0,0,0,5},
		{5,0,0,0,4,1,1,1,1,1,4,0,0,0,0,5},
		{5,0,0,0,4,0,0,0,0,0,4,0,0,0,3,5},
		{5,2,0,6,4,0,0,2,0,6,4,0,0,6,0,5},
		{5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5},
	};
	
	Map map = Map();
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			Vector2 position = Vector2(j * tileSize, i * tileSize);
			AddGameObjectByMapIndex(map.gameObjects, mapTiles[i][j], position);
			Options::options.at("mapWidth") = 16 * tileSize;
			Options::options.at("mapHeight") = 16 * tileSize;
		}
	}
	return map;
}
