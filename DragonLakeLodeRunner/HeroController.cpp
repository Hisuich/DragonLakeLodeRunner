#include "HeroController.h"
#include "GameObjects.h"

Vector2 HeroController::FindFloorPosition(bool left)
{
	Vector2 playerPos = gameObjects->GetPositionByIndex(playerIndex);
	Vector2Int playerSize = gameObjects->GetSizeByIndex(playerIndex);
	Vector2 floorPos = playerPos;
	floorPos.y += 48;
	floorPos.x += 16;

	int firstIndex = gameObjects->GetIndexByPosition(floorPos);
	floorPos.x += 32;
	int secondIndex = gameObjects->GetIndexByPosition(floorPos);
	if (left && firstIndex == -1) return Vector2(-1,-1);
	if (!left && secondIndex == -1) return Vector2(-1,-1);
	Vector2 firstFloor = gameObjects->GetPositionByIndex(firstIndex);
	Vector2 secondFloor = gameObjects->GetPositionByIndex(secondIndex);

	float firstDistance = abs(firstFloor.x - playerPos.x);
	float secondDistance = abs(secondFloor.x - playerPos.x);

	if (firstDistance > secondDistance) 
		return secondFloor;
	else return firstFloor;
}

void HeroController::SpawnBullet(bool left)
{
	Vector2 bulletPos = gameObjects->GetPositionByIndex(playerIndex);
	bulletPos.x += left ? -16 : 48;
	bulletPos.y += 48;

	gameObjects->AddGameObject(bulletPos, createSprite("data/bullet.png"), GameObjectType::Bullet, GameObjectState::Object, Vector2Int(4,4));

}

HeroController::HeroController() : UnitController()
{
	playerIndex = -1;
	speed = 30;
	mousePosition = Vector2(0, 0);
}

void HeroController::Process(float delta)
{
	if (gameObjects != nullptr)
	{
	 	playerIndex = gameObjects->GetFirstIndexByType(GameObjectType::Hero);
	}
	if (gameObjects->NeedToRemove(playerIndex)) playerIndex = -1;

	if (playerIndex != -1)
	{
		Vector2 velocity = gameObjects->GetVelocityByIndex(playerIndex);
		gameObjects->SetVelocity(playerIndex, velocity);
	}
}

void HeroController::onMouseMove(int x, int y, int xrelative, int yrelative)
{
	mousePosition.x = x;
	mousePosition.y = y;
}

void HeroController::onMouseButtonClick(FRMouseButton button, bool isReleased)
{
	if (button == FRMouseButton::LEFT && isReleased)
	{
		Vector2 playerPos = gameObjects->GetPositionByIndex(playerIndex);
		float distance = mousePosition.x - playerPos.x;
		Vector2 floor = FindFloorPosition(distance < 0);
		playerPos.x = floor.x;
		if (floor == Vector2(-1, -1)) return;
		gameObjects->SetPosition(playerIndex,playerPos);
		SpawnBullet(distance < 0);

	}
}

void HeroController::onKeyPressed(FRKey k)
{
	Vector2 velocity = gameObjects->GetVelocityByIndex(playerIndex);

	if (gameObjects->GetStateByIndex(playerIndex) != GameObjectState::Trapped)
	{
		if (k == FRKey::RIGHT)
			velocity.x = speed;
		if (k == FRKey::LEFT)
			velocity.x = -speed;
	}
	if (gameObjects->GetStateByIndex(playerIndex) == GameObjectState::Ladder)
	{
		if (k == FRKey::UP)
			velocity.y = -speed;
		else if (k == FRKey::DOWN)
			velocity.y = speed;
	}
	std::cout << "hero velocity " << velocity.x << " " << velocity.y << std::endl;

	gameObjects->SetVelocity(playerIndex, velocity);
}

void HeroController::onKeyReleased(FRKey k)
{
	Vector2 velocity = gameObjects->GetVelocityByIndex(playerIndex);
	if (k == FRKey::RIGHT || k == FRKey::LEFT) velocity.x = 0;

	if (k == FRKey::UP || k == FRKey::DOWN) velocity.y = 0;

	gameObjects->SetVelocity(playerIndex, velocity);
}
