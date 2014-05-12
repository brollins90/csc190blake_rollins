#ifndef MATRIX2D_H
#define MATRIX2D_H
#include "Vector2D.h"

namespace Engine
{
	struct Matrix2D
	{
	public:
		float m[2][2];
		// __    __
		// | 0  1 |
		// | 2  3 |
		// __    __

		Engine::Matrix2D(void)
		{
			m[0][0] = 1; m[0][1] = 0;
			m[1][0] = 0; m[1][1] = 1;
		}

		Engine::Matrix2D(const float f0, const float f1, const float f2, const float f3)
		{
			m[0][0] = f0; m[0][1] = f1;
			m[1][0] = f2; m[1][1] = f3;
		}
		
		Engine::Matrix2D(const Vector2D& v1, const Vector2D& v2)
		{
			m[0][0] = v1.x; m[0][1] = v2.x;
			m[1][0] = v1.y; m[1][1] = v2.y;
		}

		inline Matrix2D operator* (const Matrix2D& other)
		{
			return Matrix2D(Vector2D((m[0][0] * other.m[0][0]) + (m[1][0] * other.m[0][1]), (m[0][1] * other.m[0][0]) + (m[1][1] * other.m[0][1])),
							Vector2D((m[0][0] * other.m[1][0]) + (m[1][0] * other.m[1][1]), (m[0][1] * other.m[1][0]) + (m[1][1] * other.m[1][1])));
		}

		inline Vector2D operator* (const Vector2D& other)
		{
			return Vector2D((m[0][0] * other.x) + (m[0][1] * other.y), 
							(m[1][0] * other.x) + (m[1][1] * other.y));
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
			return Matrix2D(Vector2D(m[0][0] * scale, m[1][0]),
							Vector2D(m[0][1], m[1][1] * scale));
		}

		inline Matrix2D ScaleX( float scale )
		{
			return Matrix2D(Vector2D(m[0][0] * scale, m[1][0]),
							Vector2D(m[0][1], m[1][1]));
		}

		inline Matrix2D ScaleY( float scale )
		{
			return Matrix2D(Vector2D(m[0][0]	, m[1][0]),
							Vector2D(m[0][1], m[1][1] * scale));
		}
	};
}

#endif