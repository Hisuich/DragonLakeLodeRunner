#include "Vector2Int.h"

Vector2Int::Vector2Int()
{
	this->x = 0;
	this->y = 0;
}

Vector2Int::Vector2Int(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Vector2Int::Add(int x, int y)
{
	this->x += x;
	this->y += y;

}

void Vector2Int::Scale(int x, int y)
{
	this->x *= x;
	this->y *= y;
}

float Vector2Int::GetMagnitude()
{
	return sqrt(GetSqrMagnitude());
}

float Vector2Int::GetSqrMagnitude()
{
	return pow(x, 2) + pow(y, 2);
}

Vector2Int& Vector2Int::operator+(Vector2Int a)
{
	this->x += a.x;
	this->y += a.y;
	return *this;
}

Vector2Int& Vector2Int::operator-(Vector2Int a)
{
	this->x -= a.x;
	this->y -= a.y;
	return *this;
}

bool Vector2Int::operator==(Vector2Int a)
{
	return this->x == a.x && this->y == a.y;
}
