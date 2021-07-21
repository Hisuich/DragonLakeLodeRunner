#pragma once
#include <math.h>

class Vector2Int
{
public:
	int x, y;

public:
	Vector2Int();
	Vector2Int(int x, int y);

	void Add(int x, int y);

	void Scale(int x, int y);

	float GetMagnitude();
	float GetSqrMagnitude();

	Vector2Int& operator+(Vector2Int a);
	Vector2Int& operator-(Vector2Int a);
	bool operator==(Vector2Int a);
};