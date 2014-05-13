#ifndef MATRIX2D_H
#define MATRIX2D_H
#include "Vector2D.h"

namespace Engine
{
	struct Matrix2D
	{
	public:
		float m[4];
		// __    __
		// | 0  1 |
		// | 2  3 |
		// __    __

		Engine::Matrix2D(void)
		{
			m[0] = 1; m[1] = 0;
			m[2] = 0; m[3] = 1;
		}

		Engine::Matrix2D(const float f0, const float f1, const float f2, const float f3)
		{
			m[0] = f0; m[1] = f1;
			m[2] = f2; m[3] = f3;
		}
		
		Engine::Matrix2D(const Vector2D& v1, const Vector2D& v2)
		{
			m[0] = v1.x; m[1] = v2.x;
			m[2] = v1.y; m[3] = v2.y;
		}

		inline Matrix2D operator* (const Matrix2D& other)
		{
			return Matrix2D(
				m[0] * other.m[0] + m[1] * other.m[2], m[0] * other.m[1] + m[1] * other.m[3],
				m[2] * other.m[0] + m[3] * other.m[2], m[2] * other.m[1] + m[3] * other.m[3]);
		}

		inline Vector2D operator* (const Vector2D& other)
		{
			return Vector2D(m[0] * other.x + m[1] * other.y, 
							m[2] * other.x + m[3] * other.y);
		}

		inline Matrix2D Rotation( float angle )
		{
			// TODO
			//
			//
			//
			//
			//
			//
			angle;
		}

		inline Matrix2D Scale( float scale )
		{
			return Matrix2D(
				m[0] * scale,	m[1],
				m[2],			m[3] * scale);
		}

		inline Matrix2D ScaleX( float scale )
		{
			return Matrix2D(
				m[0] * scale,	m[1],
				m[2],			m[3]);
		}

		inline Matrix2D ScaleY( float scale )
		{
			return Matrix2D(
				m[0], m[1],
				m[2], m[3] * scale);
		}
	};
}

#endif