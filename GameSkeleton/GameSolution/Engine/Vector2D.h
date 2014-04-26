
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
			return Vector2D(this->x / other.x, this->y / other.y);
		}
		
		// float * Vector2
		inline Vector2D operator * (const float& other)
		{
			return Vector2D(other * this->x, other * this->y);
		}

		// Vector2 / float
		inline Vector2D operator / (const float& other)
		{
			return Vector2D(this->x / other, this->y / other);
		}

		// CrossProduct
		float CrossProduct(const Vector2D& a, const Vector2D& b)
		{
			return ((a.x * b.y) + (a.y * b.x));
		}

		// DotProduct
		float DotProduct(const Vector2D& a, const Vector2D& b)
		{
			return ((a.x * a.y) + (b.x * b.y));
		}

		// Length() 
		inline double Length()
		{
			return sqrt(pow(this->x, 2.0) + pow(this->y, 2.0));
		}
		
		// float LengthSquared()
		inline double LengthSquared()
		{
			return pow(this->x, 2.0) + pow(this->y, 2.0);
		}
		
		// LERP
		/*inline float LERP(const Vector2D& left, const Vector2D& right, const float& scaler)
		{
			return ((1.0F - scaler) * left + (scaler * right));
		}*/

		//// Negate()
		//inline Vector2D Negate()
		//{
		//	return Vector2D((-1 * (this->x)),(-1 * (this->y)));
		//}
		
		// Normalized()
		inline Vector2D Normalize()
		{
			float ratio = static_cast<float>((1.0F / this->Length()));
			return Vector2D((ratio * this->x),(ratio * this->y));
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
