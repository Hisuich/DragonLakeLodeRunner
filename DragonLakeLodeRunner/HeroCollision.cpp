#include "HeroCollision.h"
#include "GameObjects.h"

HeroCollision::HeroCollision() : UnitCollision()
{
	collisionType = GameObjectType::Hero;
}

void HeroCollision::CollisionProcess(float delta, int index, int second)
{
	Vector2 heroVelocity = gameObjects->GetVelocityByIndex(index);
	Vector2 heroPos = gameObjects->GetPositionByIndex(index);

	GameObjectType secondType = gameObjects->GetTypeByIndex(second);

	if (secondType == GameObjectType::Ladder)
	{
		gameObjects->SetState(index, GameObjectState::Ladder);
	}

	else if (secondType == GameObjectType::DestructableFloor)
	{
		if (gameObjects->GetStateByIndex(second) == GameObjectState::DestructedFloor)
		{

			if (heroPos.y >= gameObjects->GetPositionByIndex(second).y)
			{
				gameObjects->SetState(index, GameObjectState::Trapped);
				heroVelocity.y = heroVelocity.y > 0 ? 0 : heroVelocity.y;
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
			heroVelocity.y = 0;
		}
	}

	else if (secondType == GameObjectType::Floor ||
		secondType == GameObjectType::DestructableFloor ||
		secondType == GameObjectType::Enemy ||
		secondType == GameObjectType::Trapdoor)
	{
		heroVelocity.y = 0;
	}

	if (secondType == GameObjectType::Wall)
	{
		heroPos.x -= heroVelocity.x * delta;
	}

	if (secondType == GameObjectType::Gold)
	{
		//Options::levelParams.at("currentGold") += 1;
		gameObjects->RemoveAtIndex(second);
	}
	gameObjects->SetPosition(index, heroPos);
	gameObjects->SetVelocity(index, heroVelocity);

	if (secondType == GameObjectType::Enemy)
	{
		if (gameObjects->GetStateByIndex(second) != GameObjectState::Trapped)
		{
			std::cout << "hero index: " << index << std::endl;
			gameObjects->RemoveAtIndex(index);
		}
	}
}
