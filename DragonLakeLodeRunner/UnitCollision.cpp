#include "UnitCollision.h"
#include "GameObjects.h"

UnitCollision::UnitCollision()
{
	mask = 2;
}

void UnitCollision::SetGameObjects(GameObjects* gameObjects)
{
	this->gameObjects = gameObjects;
}

void UnitCollision::Collision(float delta, int first, int second)
{
	if (isCollisionType(gameObjects->GetTypeByIndex(first)))
		CollisionProcess(delta, first, second);
}

bool UnitCollision::isCollisionType(GameObjectType type)
{
	return collisionType == type;
}

void UnitCollision::Solid(float delta, int first, int second)
{
	Vector2 firstPos = gameObjects->GetPositionByIndex(first);

	Vector2 velocity = gameObjects->GetVelocityByIndex(first);

	Vector2 secondPos = gameObjects->GetPositionByIndex(second);

	Vector2 distance = secondPos - firstPos;
	if (abs(distance.x) > abs(distance.y)) distance.y = 0;
	if (abs(distance.y) > abs(distance.x)) distance.x = 0;

	if (distance.x > 0 || distance.x < 0)
	{
		velocity.x = 0;
	}
	if (distance.y > 0 || distance.y < 0)
		velocity.y = 0;
		


		gameObjects->SetVelocity(first, velocity);
	gameObjects->SetPosition(first, firstPos);
}
