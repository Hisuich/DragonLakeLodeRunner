#include "EndLevelSpawner.h"
#include "GameObjects.h"

EndLevelSpawner::EndLevelSpawner()
{
	endLevelIndex = -1;
	exitSpawned = false;
}

void EndLevelSpawner::Process(float delta)
{
	if (endLevelIndex == -1)
		FindEndLevel();
}

void EndLevelSpawner::FindEndLevel()
{
	if (gameObjects == nullptr) return;

	endLevelIndex = gameObjects->GetFirstIndexByType(GameObjectType::ExitPoint);
}

void EndLevelSpawner::SpawnEndLevel()
{
	if (endLevelIndex == -1) return;
	Vector2 pos = gameObjects->GetPositionByIndex(endLevelIndex);
	gameObjects->AddGameObject(pos, createSprite("data/exit.png"), GameObjectType::Exit, GameObjectState::Object);
	exitSpawned = true;
}
