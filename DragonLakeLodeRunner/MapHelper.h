#pragma once
#include "Framework.h"
#include "Map.h"
#include "GameObjectState.h"
#include <unordered_map>
#include <string>
#include "Options.h"

class MapHelper
{
public:
	static const int tileSize = 32;

private:
	void AddGameObjectByMapIndex(GameObjects* gameObjects, int index, Vector2 position);

public:
	Map GetHardcodeMap();
};