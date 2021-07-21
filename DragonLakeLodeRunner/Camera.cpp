#include "Camera.h"
#include <iostream>

Camera::Camera()
{
	getScreenSize(screenWidth, screenHeight);
}

void Camera::Init()
{
	SetMapSize();
}

void Camera::SetLockPosition(Vector2 position)
{
	lockPosition = position;
}

void Camera::SetMapSize()
{
	this->mapSize = Vector2Int(Options::options.at("mapWidth"), Options::options.at("mapHeight"));
	SetThreshold();
}

Vector2 Camera::GetOffset()
{
	Vector2 offset = Vector2(lockPosition.x - (mapSize.x / 2), lockPosition.y - (mapSize.y / 2));

	if (offset.x < xThreshold.x) offset.x = xThreshold.x;
	if (offset.x > xThreshold.y) offset.x = xThreshold.y;
	if (offset.y < yThreshold.x) offset.y = yThreshold.x;
	if (offset.y > yThreshold.y) offset.y = yThreshold.y;

	return offset;
}

Vector2 Camera::SetThreshold()
{
	xThreshold = Vector2Int(0, mapSize.x - (screenWidth));
	yThreshold = Vector2Int(0, mapSize.y - (screenHeight));
	return Vector2();
}