
#ifndef VECTOR2D_H
#define VECTOR2D_H

namespace Engine
{
	struct Vector2D
	{
	public:
		float x, y;
		Engine::Vector2D(float x = 0, float y = 0)
		{

			this->x = x;
			this->y = y;
		} 

		std::ostream& operator<<(std::ostream& stream)
		{

			std::cout << "{" << this->x << "," << this->y << "}";
			return stream;
		} 

		// Conversion
		float operator[] (int index)
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

		Vector2D operator + (const Vector2D& other)
		{
			return Vector2D(this->x + other.x, this->y + other.y);
		}

		Vector2D operator - (const Vector2D& other)
		{
			return Vector2D(this->x - other.x, this->y - other.y);
		}

		Vector2D operator * (const Vector2D& other)
		{
			return Vector2D(this->x * other.x, this->y * other.y);
		}

		Vector2D operator / (const Vector2D& other)
		{
			return Vector2D(this->x / other.x, this->y / other.y);
		}
	//	// float * Vector2
	//	friend Vector2 operator*(const float& left, const Vector2& right);
	//	// Vector2 * float
	////	friend Vector2 operator*(const Vector2& left, const float& right);
	//	// Vector2 / float
	//	friend Vector2 operator/(const Vector2& left, const float& right);
	//	// LERP
	//	//friend Vector2 LERP(const Vector2& left, const Vector2& right, const float& scaler);
	//	// o	float Length() 
	//	float Length();
	//	// o	float LengthSquared()
	//	float LengthSquared();
	//	// o	Normalized()
	//	// o	PerpCW
	//	// o	PerpCCW
	//	// o	Dot
	//	//friend float DotProduct(const Vector2& a, const Vector2& b);
	//	// o	Cross
	};
}
#endif
