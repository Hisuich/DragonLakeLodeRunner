#pragma once
#include "Framework.h"
#include "GameObjects.h"

#include "HeroCollision.h"
#include "EnemyCollision.h"
#include "BulletCollision.h"

#include "HeroController.h"
#include "EnemyController.h"
#include "DestructFloorController.h"

#include "HeroSpawner.h"
#include "EnemySpawner.h"

#include <iostream>

class Map
{
public:
	GameObjects* gameObjects;


private:
	Sprite* background;

public:
	Map();
	~Map();
	void Init();
	void Update(float deltaTime);
	void Draw();

	void onMouseMove(int x, int y, int xrelative, int yrelative);

	void onMouseButtonClick(FRMouseButton button, bool isReleased);

	void onKeyPressed(FRKey k);

	void onKeyReleased(FRKey k);
};