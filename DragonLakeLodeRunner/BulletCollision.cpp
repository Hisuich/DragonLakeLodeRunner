#include "BulletCollision.h"
#include "GameObjects.h"

BulletCollision::BulletCollision()
{
	collisionType = GameObjectType::Bullet;
}

void BulletCollision::CollisionProcess(float delta, int index, int second)
{
	GameObjectType secondType = gameObjects->GetTypeByIndex(second);
	std::cout << "Bullet pos " << gameObjects->GetPositionByIndex(index).x << " " << gameObjects->GetPositionByIndex(index).y << std::endl;
	std::cout << "Second pos " << gameObjects->GetPositionByIndex(second).x << " " << gameObjects->GetPositionByIndex(second).y << std::endl;
	std::cout << "Bullet collision " << second << " " << (gameObjects->GetTypeByIndex(second) == GameObjectType::DestructableFloor) << std::endl;
	gameObjects->RemoveAtIndex(index);

	if (secondType == GameObjectType::DestructableFloor)
	{
		std::cout << "DestructableFloor" << std::endl;
		gameObjects->SetState(second, GameObjectState::DestructedFloor);
	}
}
