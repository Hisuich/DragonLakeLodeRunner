#include "Vector2.h"

Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector2::Add(float x, float y)
{
	this->x += x;
	this->y += y;

}

void Vector2::Scale(float x, float y)
{
	this->x *= x;
	this->y *= y;
}

float Vector2::GetMagnitude()
{
	return sqrt(GetSqrMagnitude());
}

float Vector2::GetSqrMagnitude()
{
	return pow(x, 2) + pow(y, 2);
}

Vector2 Vector2::GetNormalize()
{
	float magnitude = GetMagnitude();
	return Vector2(x/magnitude, y/magnitude);
}

Vector2& Vector2::operator+(Vector2 a)
{
	this->x += a.x;
	this->y += a.y;
	return *this;
}

Vector2& Vector2::operator-(Vector2 a)
{

	this->x -= a.x;
	this->y -= a.y;
	return *this;
}

bool Vector2::operator==(Vector2 a)
{
	return this->x == a.x && this->y == a.y;
}
