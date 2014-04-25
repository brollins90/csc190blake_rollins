#include <iostream>
#include <math.h>
#include "Engine.h"
#include "Vector2.h"
using Engine::Vector2;

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}


std::ostream& operator<<(std::ostream& stream, const Vector2& right)
{
	std::cout << "{" << right.x << "," << right.y << "}";
	return stream;
}

float Vector2::operator[] (int index)
{
	if ( index == 0) 
	{
		return this->x;
	}
	else if ( index == 1)
	{
		return this->y;
	}
	else
	{
		return 0.0F;
	}
}


Vector2 operator+(const Vector2& left, const Vector2& right)
{
	return Vector2(left.x + right.x, left.y + right.y);
}

Vector2 operator-(const Vector2& left, const Vector2& right)
{
	return Vector2(left.x - right.x, left.y - right.y);
}

Vector2 operator*(const Vector2& left, const Vector2& right)
{
	return Vector2(left.x * right.x, left.y * right.y);
}

Vector2 operator/(const Vector2& left, const Vector2& right)
{
	return Vector2(left.x / right.x, left.y / right.y);
}

//Vector2 operator*(const float& left, const Vector2& right)
//{
//	return Vector2(left * right.x, left * right.y);
//}
//
//Vector2 operator*(const Vector2& left, const float& right)
//{
//	return Vector2(left.x * right, left.y);
//}
//
//Vector2 operator/(const Vector2& left, const float& right)
//{
//	return Vector2(left.x / right, left.y / right);
//}
//
////Vector2 LERP(const Vector2& left, const Vector2& right, const float& scaler)
////{
////	return ((1.0F - scaler) * left + (scaler * right));
////}
//
//float Vector2::Length()
//{
//	return sqrt(pow(this->x, 2.0) + pow(this->y, 2.0));
//}
//
//float Vector2::LengthSquared()
//{
//	return (pow(this->x, 2.0) + pow(this->y, 2.0));
//}
//
//float DotProduct(const Vector2& a, const Vector2& b)
//{
//	return ((a.x * a.y) + (b.x * b.y));
//}