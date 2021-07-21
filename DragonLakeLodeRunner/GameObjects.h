#pragma once
#include "Framework.h"
#include "Collisions.h"
#include "Controllers.h"
#include "Spawners.h"
#include "Vector2.h"
#include "Vector2Int.h"
#include "GameObjectType.h"
#include "GameObjectState.h"

#include <iostream>
#include <vector>

using std::vector;

class Camera;

class GameObjects
{
private:
	vector<Vector2> positions;
	vector<Vector2Int> sizes;
	vector<Sprite*> sprites;
	vector<GameObjectState> states;
	vector<GameObjectType> types;
	vector<Vector2> velocities;

	vector<int> needToRemove;

	static int tileSize;

public:
	Camera* camera;
	std::unique_ptr<Spawners> spawners;
	std::unique_ptr<Collisions> collisions;
	std::unique_ptr<Controllers> controllers;

private:
	Vector2 GetOffsetPosition(int index);
	bool HaveIndex(int index);

	void RemoveAt(int index);
	void RemoveGameObjects();

public:
	GameObjects();
	void Update(float deltaTime);
	void Draw();

	void AddGameObject(Vector2 position, Sprite* sprite, GameObjectType type, GameObjectState state, Vector2Int size = Vector2Int(tileSize, tileSize), Vector2 velocity = Vector2(0,0));

	Vector2 GetPositionByIndex(int index);
	Vector2Int GetSizeByIndex(int index);
	GameObjectType GetTypeByIndex(int index);
	Vector2 GetVelocityByIndex(int index);
	GameObjectState GetStateByIndex(int index);

	bool NeedToRemove(int index);

	void SetPosition(int index, Vector2 position);
	void SetVelocity(int index, Vector2 velocity);
	void SetSprite(int index, Sprite* sprite);
	void SetState(int index, GameObjectState state);

	int GetObjectNumber();

	int GetIndexByPosition(Vector2 position);

	// return -1 if there is no such type
	int GetFirstIndexByType(GameObjectType type);

	// return -1 if there is no such type
	vector<int> GetIndexesByType(GameObjectType type);

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative);

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);

	virtual void onKeyPressed(FRKey k);

	virtual void onKeyReleased(FRKey k);

	// Set object as needToRemove
	void RemoveAtIndex(int index);
	void RemoveAtPosition(Vector2 position);
};