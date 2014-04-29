
#ifndef VECTOR2D_H
#define VECTOR2D_H

namespace Engine
{
	struct Vector2D
	{
	public:
		float x, y;
		Engine::Vector2D(float x = 0, float y = 0) : x(x), y(y) {}

		std::ostream& operator<<(std::ostream& stream)
		{
			std::cout << "{" << this->x << "," << this->y << "}";
			return stream;
		}

		inline Vector2D operator+ (const Vector2D& other) {	return Vector2D(x + other.x, y + other.y); }
		inline Vector2D operator- (const Vector2D& other) { return Vector2D(x - other.x, y - other.y); }
		inline Vector2D operator* (const Vector2D& other) { return Vector2D(x * other.x, y * other.y); }
		inline Vector2D operator* (const float& other) { return Vector2D(x * other, y * other); }		
		friend inline Vector2D operator* (const Vector2D& lhs, const float& rhs) { return Vector2D(lhs.x * rhs, lhs.y * rhs); }		
		friend inline Vector2D operator* (const float& lhs, const Vector2D& rhs) { return Vector2D(lhs * rhs.x, lhs * rhs.y); }
		inline Vector2D operator/ (const Vector2D& other) 
		{
			if (other.x != 0 && other.y != 0)
			{
				return Vector2D(x / other.x, y / other.y);
			}
			else
			{
				return Vector2D(0,0);
			}
		}
		inline Vector2D operator/ (const float& other)
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
		
		inline float CrossProduct(const Vector2D& other) { return ((x * other.y) - (y * other.x)); }

		inline float DotProduct(const Vector2D& other) { return ((x * other.x) + (y * other.y)); }
		static inline float DotProduct(const Vector2D& lhs, const Vector2D& rhs) { return ((lhs.x * rhs.x) + (lhs.y * rhs.y)); }
		
		inline float Length() { return sqrt(x * x + y * y); }
		inline float LengthSquared() { return (x * x + y * y); }
		// LERP
		static inline Vector2D LERP(const Vector2D& start, const Vector2D& end, const float& percent)
		{
			Vector2D aVectorLerpPortion = start * (1.0F - percent);
			Vector2D bVectorLerpPortion = end * percent;
			return aVectorLerpPortion + bVectorLerpPortion;
		}

		// Negate()
		inline Vector2D Negate() { return Vector2D((-1 * (x)),(-1 * (y))); }
		
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

		inline Vector2D PerpCW() { return Vector2D(y, (-1) * x); }
		inline Vector2D PerpCCW() { return Vector2D((-1) * y, x); }
	};
}
#endif
