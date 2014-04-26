
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

		inline Vector2D operator + (const Vector2D& other)
		{
			return Vector2D(this->x + other.x, this->y + other.y);
		}

		inline Vector2D operator - (const Vector2D& other)
		{
			return Vector2D(this->x - other.x, this->y - other.y);
		}

		inline Vector2D operator * (const Vector2D& other)
		{
			return Vector2D(this->x * other.x, this->y * other.y);
		}

		inline Vector2D operator / (const Vector2D& other)
		{
			if (other.x != 0 && other.y != 0)
			{
				return Vector2D(this->x / other.x, this->y / other.y);
			}
			else
			{
				return Vector2D(0,0);
			}
		}
		
		// float * Vector2
		inline Vector2D operator * (const float& other)
		{
			return Vector2D(other * this->x, other * this->y);
		}

		// Vector2 / float
		inline Vector2D operator / (const float& other)
		{
			if (other != 0)
			{
				return Vector2D(this->x / other, this->y / other);
			}
			else
			{
				return Vector2D(0,0);
			}
		}

		// CrossProduct
		float CrossProduct(const Vector2D& other)
		{
			return ((this->x * other.y) - (this->y * other.x));
		}

		// DotProduct
		float DotProduct(const Vector2D& other)
		{
			return ((this->x * other.x) + (this->y * other.y));
		}

		// Length() 
		inline float Length()
		{
			return sqrt(this->x * this->x + this->y * this->y);
		}
		
		// float LengthSquared()
		inline float LengthSquared()
		{
			return (this->x * this->x + this->y * this->y);
		}
		
		//// LERP
		//float LERP2(const Vector2D& start, const Vector2D& end, const float& percent)
		//{
		//	return (start + percent * (end - start));
		//}

		//inline float LERP(const Vector2D& left, const Vector2D& right, const float& scalar)
		//{

		//	return (left + scalar * (right - left));
		//}

		//// Negate()
		//inline Vector2D Negate()
		//{
		//	return Vector2D((-1 * (this->x)),(-1 * (this->y)));
		//}
		
		// Normalized()
		inline Vector2D Normalize()
		{
			Vector2D vect;
			float length = this->Length();

			if (length != 0)
			{
				vect.x = x / length;
				vect.y = y / length;
			}
			return vect;
		}

		// PerpCW
		inline Vector2D PerpCW()
		{
			return Vector2D(this->y, (-1) * this->x);
		}
			
		// PerpCCW
		inline Vector2D PerpCCW()
		{
			return Vector2D((-1) * this->y, this->x);
		}
	};
}
#endif
