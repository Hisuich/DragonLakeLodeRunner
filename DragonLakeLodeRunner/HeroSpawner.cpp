#include "HeroSpawner.h"
#include "GameObjects.h"

HeroSpawner::HeroSpawner()
{
	heroSpawnIndex = -1;
	playerIndex = -1;

}

void HeroSpawner::FindHeroSpawn()
{
	if (gameObjects != nullptr)
		heroSpawnIndex = gameObjects->GetFirstIndexByType(GameObjectType::HeroSpawnPoint);
}

void HeroSpawner::SpawnHero()
{
	if (gameObjects != nullptr && heroSpawnIndex != -1)
	{
		Vector2 pos = gameObjects->GetPositionByIndex(heroSpawnIndex);
		Options::levelParams.at("heroLife") -= 1;
		gameObjects->AddGameObject(pos, createSprite("data/hero.png"), GameObjectType::Hero, GameObjectState::Idle);
		//playerIndex = gameObjects->GetObjectNumber()-1;
	}
		
}

void HeroSpawner::Process(float deltaTime)
{
	if (heroSpawnIndex != -1)
		playerIndex = gameObjects->GetFirstIndexByType(GameObjectType::Hero);
	if (heroSpawnIndex == -1)
		FindHeroSpawn();
	if (playerIndex == -1)
	{
		SpawnHero();
	}

	if (gameObjects->NeedToRemove(playerIndex))
	{
		playerIndex = -1;
	}
}
