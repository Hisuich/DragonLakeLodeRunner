#include "Collisions.h"
#include "GameObjects.h"

Collisions::Collisions(GameObjects* gameObjects)
{
	this->gameObjects = gameObjects;
	mask = 1;
}

void Collisions::AddCollision(UnitCollision_sptr collision)
{
	collision->SetGameObjects(gameObjects);
	collisions.push_back(collision);
}

void Collisions::Process(float delta)
{
	int objectNumber = gameObjects->GetObjectNumber();

	if (objectNumber <= 0) return;

	for (int i = 0; i < objectNumber; i++)
	{
		Vector2 firstPos = gameObjects->GetPositionByIndex(i);
		Vector2Int firstSize = gameObjects->GetSizeByIndex(i);
		Vector2 velocity = gameObjects->GetVelocityByIndex(i);
		GameObjectState state = gameObjects->GetStateByIndex(i);

		for (int j = 0; j < objectNumber; j++)
		{
			if (i == j) continue;

			Vector2 secondPos = gameObjects->GetPositionByIndex(j);
			Vector2Int secondSize = gameObjects->GetSizeByIndex(j);

			if (firstPos.x + firstSize.x - mask > secondPos.x &&
				firstPos.x + mask < secondPos.x + secondSize.x &&
				firstPos.y + firstSize.y - mask > secondPos.y &&
				firstPos.y + mask < secondPos.y + secondSize.y)
			{
				if (j == 3) std::cout << "Collision down" << std::endl;
				Collision(delta, i, j);
			}
		}
	}
}

void Collisions::Collision(float delta, int first, int second)
{
	for (int i = 0; i < collisions.size(); i++)
	{
		collisions[i]->Collision(delta, first, second);
	}
}
