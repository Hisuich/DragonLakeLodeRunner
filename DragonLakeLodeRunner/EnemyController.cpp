#include "EnemyController.h"
#include "GameObjects.h"

void EnemyController::EnemyControl(int index, Vector2 playerPos)
{
	GameObjectState enemyState = gameObjects->GetStateByIndex(index);
	GameObjectType enemyType = gameObjects->GetTypeByIndex(index);
	Vector2 velocity = gameObjects->GetVelocityByIndex(index);

	Vector2 enemyPos = gameObjects->GetPositionByIndex(index);
	int direction;
	// player is up
	if (enemyPos.y - playerPos.y > 5)
		direction = 2;
	else if (enemyPos.y - playerPos.y < -5)
		direction = 3;
	// player if left
	else if (enemyPos.x > playerPos.x)
		direction = 0;
	// player if right
	else if (enemyPos.x < playerPos.x)
		direction = 1;

	std::cout << "direction " << direction << std::endl;

	if (direction == 0)
		velocity.x = -speed;
	if (direction == 1)
		velocity.x = speed;

	if (enemyState == GameObjectState::Ladder)
	{
		if (direction == 0 || direction == 1)
			velocity.y = 0;
	}

	Vector2 ladderPos = FindLadder(index);
	/*if (ladderPos == Vector2(-1, -1))
	{
		direction = rand() % 2;
		velocity.x = direction == 0 ? -speed : speed;
	}*/
		if (direction == 2 || direction == 3)
		{
			if (enemyPos.x > ladderPos.x) velocity.x = -speed;
			else if (enemyPos.x < ladderPos.x) velocity.x = speed;

			if (enemyState == GameObjectState::Ladder)
			{
				Vector2 ladderPos = FindLadder(index);
				if (velocity.x > speed)
				{
					if (enemyPos.x <= ladderPos.x)
					{
						velocity.x = 0;
						if (direction == 2)
							velocity.y = -speed;
						if (direction == 3)
							velocity.y = speed;
					}
				}
				if (velocity.x < speed)
				{
					if (enemyPos.x >= ladderPos.x)
					{
						velocity.x = 0;
						if (direction == 2)
							velocity.y = -speed;
						if (direction == 3)
							velocity.y = speed;
					}
				}
			}
		}

		

	gameObjects->SetVelocity(index, velocity);
}

Vector2 EnemyController::FindLadder(int index)
{
	float offset = 0;
	Vector2 enemyPos = gameObjects->GetPositionByIndex(index);

	while (enemyPos.x - offset > 0 && enemyPos.x + offset < Options::options.at("mapWidth"))
	{
		Vector2 leftPos = Vector2(enemyPos.x - offset, enemyPos.y);
		Vector2 rightPos = Vector2(enemyPos.x + offset, enemyPos.y);

		int leftIndex = gameObjects->GetIndexByPosition(leftPos);
		int rightIndex = gameObjects->GetIndexByPosition(rightPos);
		offset += 32;
		if (gameObjects->GetTypeByIndex(leftIndex) == GameObjectType::Ladder)
			return gameObjects->GetPositionByIndex(leftIndex);
		else if (gameObjects->GetTypeByIndex(rightIndex) == GameObjectType::Ladder)
			return gameObjects->GetPositionByIndex(rightIndex);
	}
	return Vector2(-1, -1);
	
}

EnemyController::EnemyController() : UnitController()
{
	speed = 30;
}

void EnemyController::Process(float delta)
{
	if (gameObjects != nullptr)
	{
		enemiesIndex = gameObjects->GetIndexesByType(GameObjectType::Enemy);
	}
	Vector2 playerPos = gameObjects->GetPositionByIndex(gameObjects->GetFirstIndexByType(GameObjectType::Hero));
	for (int i = 0; i < enemiesIndex.size(); i++)
	{
		EnemyControl(enemiesIndex[i], playerPos);
		if (gameObjects->NeedToRemove(enemiesIndex[i]))
		{
			enemiesIndex = gameObjects->GetIndexesByType(GameObjectType::Enemy);
			break;
		}
	}

}

void EnemyController::onMouseMove(int x, int y, int xrelative, int yrelative)
{
}

void EnemyController::onMouseButtonClick(FRMouseButton button, bool isReleased)
{
}

void EnemyController::onKeyPressed(FRKey k)
{
}

void EnemyController::onKeyReleased(FRKey k)
{
}
