#include "DestructFloorController.h"
#include "GameObjects.h"

void DestructFloorController::FindFloor()
{
	if (gameObjects == nullptr) return;

	floorIndexes = gameObjects->GetIndexesByType(GameObjectType::DestructableFloor);
	timers = std::vector<float>(floorIndexes.size());
	destructed = std::vector<bool>(floorIndexes.size(), false);
}

void DestructFloorController::CheckFloor()
{
	for(int i = 0; i < floorIndexes.size(); i++)
	{
		GameObjectState state = gameObjects->GetStateByIndex(floorIndexes[i]);

		if (state == GameObjectState::DestructedFloor && !destructed[i])
		{
			Destroy(i);
		}
	}
}

void DestructFloorController::CheckDestruct(float delta)
{
	for (int i = 0; i < destructed.size(); i++)
	{
		if (destructed[i])
			timers[i] += delta;
		if (timers[i] >= restoreTime)
			Restore(i);

	}
}

void DestructFloorController::Destroy(int index)
{
	std::cout << "Destroy" << std::endl;
	timers[index] = 0;
	destructed[index] = true;
	gameObjects->SetSprite(floorIndexes[index], createSprite("data/empty.png"));
}

void DestructFloorController::Restore(int index)
{
	destructed[index] = false;
	gameObjects->SetState(floorIndexes[index], GameObjectState::Object);
	gameObjects->SetSprite(floorIndexes[index], createSprite("data/floor.png"));
}

DestructFloorController::DestructFloorController()
{
}

void DestructFloorController::Process(float delta)
{
	if (floorIndexes.size() == 0)
		FindFloor();

	if (floorIndexes.size() > 0)
	{
		CheckFloor();
		CheckDestruct(delta);
	}
}

void DestructFloorController::onMouseMove(int x, int y, int xrelative, int yrelative)
{
}

void DestructFloorController::onMouseButtonClick(FRMouseButton button, bool isReleased)
{
}

void DestructFloorController::onKeyPressed(FRKey k)
{
}

void DestructFloorController::onKeyReleased(FRKey k)
{
}
