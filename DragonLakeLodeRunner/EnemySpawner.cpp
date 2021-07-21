#include "EnemySpawner.h"
#include "GameObjects.h"

EnemySpawner::EnemySpawner()
{
	enemiesIndex = std::vector<int>();
	enemySpawnsIndex = std::vector<int>();
}

void EnemySpawner::FindEnemySpawns()
{
	if (gameObjects != nullptr)
		enemySpawnsIndex = gameObjects->GetIndexesByType(GameObjectType::EnemySpawnPoint);
}

void EnemySpawner::FindEnemies()
{
	if (gameObjects == nullptr) return;

	enemiesIndex = gameObjects->GetIndexesByType(GameObjectType::Enemy);
}

void EnemySpawner::SpawnEnemies()
{
	if (gameObjects == nullptr) return;
	if (enemySpawnsIndex.size() == 0) return;
	int spawnNumber = enemySpawnsIndex.size() - enemiesIndex.size();

	for (int i = 0; i < spawnNumber; i++)
	{
		Vector2 pos = gameObjects->GetPositionByIndex(enemySpawnsIndex[rand() % enemySpawnsIndex.size()]);
		gameObjects->AddGameObject(pos, createSprite("data/enemy.png"), GameObjectType::Enemy, GameObjectState::Idle);
		enemiesIndex.push_back(gameObjects->GetObjectNumber() - 1);
	}
}

void EnemySpawner::Process(float delta)
{
	FindEnemies();

	if (enemySpawnsIndex.size() == 0)
		FindEnemySpawns();
	
	if (enemiesIndex.size() != enemySpawnsIndex.size())
		SpawnEnemies();

}
