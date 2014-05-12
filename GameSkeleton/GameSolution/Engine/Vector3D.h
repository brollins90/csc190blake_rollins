#ifndef VECTOR3D_H
#define VECTOR3D_H
#include <iostream>

namespace Engine
{
	struct Vector3D
	{
	public:
		float x, y, z;
		Engine::Vector3D(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

		std::ostream& operator<<(std::ostream& stream)
		{
			std::cout << "{" << this->x << "," << this->y << "," << this->z << "}";
			return stream;
		}

		inline Vector3D operator+ (const Vector3D& other) {	return Vector3D(x + other.x, y + other.y, z + other.z); }
		inline Vector3D operator- (const Vector3D& other) { return Vector3D(x - other.x, y - other.y, z - other.z); }
		inline Vector3D operator* (const float& other) { return Vector3D(x * other, y * other, z * other); }		
		friend inline Vector3D operator* (const Vector3D& lhs, const float& rhs) { return Vector3D(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs); }		
		friend inline Vector3D operator* (const float& lhs, const Vector3D& rhs) { return Vector3D(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z); }
		inline Vector3D operator/ (const Vector3D& other) 
		{
			if (other.x != 0 && other.y != 0 && other.z != 0)
			{
				return Vector3D(x / other.x, y / other.y, z / other.z);
			}
			else
			{
				return Vector3D(0,0,0);
			}
		}
		inline Vector3D operator/ (const float& other)
		{
			if (other != 0)
			{
				return Vector3D(this->x / other, this->y / other, this->z / other);
			}
			else
			{
				return Vector3D(0,0,0);
			}
		}
		
		/*
		inline float CrossProduct(const Vector3D& other) { return ((x * other.y) - (y * other.x)); }

		inline float DotProduct(const Vector3D& other) { return ((x * other.x) + (y * other.y)); }
		static inline float DotProduct(const Vector3D& lhs, const Vector3D& rhs) { return ((lhs.x * rhs.x) + (lhs.y * rhs.y)); }
		
		inline float Length() { return sqrt(x * x + y * y); }
		inline float LengthSquared() { return (x * x + y * y); }
		
		// LERP
		static inline Vector3D LERP(const Vector3D& start, const Vector3D& end, const float& percent)
		{
			Vector3D aVectorLerpPortion = start * (1.0F - percent);
			Vector3D bVectorLerpPortion = end * percent;
			return aVectorLerpPortion + bVectorLerpPortion;
		}

		// Negate()
		inline Vector3D Negate() { return Vector3D((-1 * (x)),(-1 * (y))); }
		
		// Normalized()
		inline Vector3D Normalize()
		{
			Vector3D vect;
			float length = this->Length();

			if (length != 0)
			{
				vect.x = x / length;
				vect.y = y / length;
				vect.z = z / length;
			}
			return vect;
		}

		inline Vector3D PerpCW() { return Vector3D(y, (-1) * x); }
		inline Vector3D PerpCCW() { return Vector3D((-1) * y, x); }
		*/
	};
}
#endif
