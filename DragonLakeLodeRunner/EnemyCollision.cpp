#include "EnemyCollision.h"
#include "GameObjects.h"

void EnemyCollision::SpawnGold(int index)
{
	Vector2 unitPos = gameObjects->GetPositionByIndex(index);
	unitPos.y -= 32;
	gameObjects->AddGameObject(unitPos, createSprite("data/gold.png"), GameObjectType::Gold, GameObjectState::Object);
}

EnemyCollision::EnemyCollision() : UnitCollision()
{
	collisionType = GameObjectType::Enemy;
	haveGold = false;
}

void EnemyCollision::CollisionProcess(float delta,int index, int second)
{
	Vector2 enemyVelocity = gameObjects->GetVelocityByIndex(index);
	Vector2 enemyPos = gameObjects->GetPositionByIndex(index);

	GameObjectType secondType = gameObjects->GetTypeByIndex(second);

	if (secondType == GameObjectType::Ladder)
	{
		gameObjects->SetState(index, GameObjectState::Ladder);
	}

	else if (secondType == GameObjectType::DestructableFloor)
	{
		if (gameObjects->GetStateByIndex(second) == GameObjectState::DestructedFloor)
		{

			if (enemyPos.y >= gameObjects->GetPositionByIndex(second).y)
			{
				if (haveGold)
				{
					SpawnGold(index);
					haveGold = false;
				}
				gameObjects->SetState(index, GameObjectState::Trapped);
				//enemyVelocity.y = enemyVelocity.y > 0 ? 0 : enemyVelocity.y;
			}
		}
		else if (gameObjects->GetStateByIndex(second) == GameObjectState::Object &&
			gameObjects->GetStateByIndex(index) == GameObjectState::Trapped)
		{
			gameObjects->RemoveAtIndex(index);
			return;
		}
		else
		{
			enemyVelocity.y = enemyVelocity.y > 0 ? 0 : enemyVelocity.y;
		}
	}
	else if (secondType == GameObjectType::Floor ||
		secondType == GameObjectType::DestructableFloor ||
		secondType == GameObjectType::Enemy ||
		secondType == GameObjectType::Trapdoor)
	{
		//enemyPos.y -= enemyVelocity.y * delta;
		//enemyVelocity.y = enemyVelocity.y > 0 ? 0 : enemyVelocity.y;
	}

	if (secondType == GameObjectType::Gold && !haveGold)
	{
		haveGold = true;
		gameObjects->RemoveAtIndex(second);
	}
	gameObjects->SetPosition(index, enemyPos);
	gameObjects->SetVelocity(index, enemyVelocity);
}
