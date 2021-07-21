#pragma once
#include <math.h>

class Vector2
{
public:
	float x, y;

public:
	Vector2();
	Vector2(float x, float y);
	void Add(float x, float y);

	void Scale(float x, float y);

	float GetMagnitude();
	float GetSqrMagnitude();

	Vector2 GetNormalize();

	Vector2& operator+(Vector2 a);
	Vector2& operator-(Vector2 a);
	bool operator==(Vector2 a);
};