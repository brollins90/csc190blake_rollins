#ifndef MATRIX3D_H
#define MATRIX3D_H
#include "Vector2D.h"

namespace Engine
{
	struct Matrix3D
	{
	public:
		float m[3][3];
		Engine::Matrix3D(void)
		{
			m[0][0] = 1; m[0][1] = 0; m[0][2] = 0;
			m[1][0] = 0; m[1][1] = 1; m[1][2] = 0;
			m[2][0] = 0; m[2][1] = 0; m[2][2] = 1;
		}
		
		Engine::Matrix3D(const Vector2D& v1, const Vector2D& v2)
		{
			m[0][0] = v1.x; m[0][1] = v2.x, m[0][2] = 0;
			m[1][0] = v1.y; m[1][1] = v2.y; m[1][2] = 0;
			m[2][0] = 0;    m[2][1] = 0;    m[2][2] = 1;
		}

		inline Matrix3D operator* (const Matrix3D& other)
		{
			return Matrix3D(Vector2D((m[0][0] * other.m[0][0]) + (m[1][0] * other.m[0][1]), (m[0][1] * other.m[0][0]) + (m[1][1] * other.m[0][1])),
							Vector2D((m[0][0] * other.m[1][0]) + (m[1][0] * other.m[1][1]), (m[0][1] * other.m[1][0]) + (m[1][1] * other.m[1][1])));
		}

		inline Vector2D operator* (const Vector2D& other)
		{
			return Vector2D((m[0][0] * other.x) + (m[0][1] * other.y), 
							(m[1][0] * other.x) + (m[1][1] * other.y));
		}

		inline Matrix3D Rotation( float angle )
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

		inline Matrix3D Scale( float scale )
		{
			return Matrix3D(Vector2D(m[0][0] * scale, m[1][0]),
							Vector2D(m[0][1], m[1][1] * scale));
		}

		inline Matrix3D ScaleX( float scale )
		{
			return Matrix3D(Vector2D(m[0][0] * scale, m[1][0]),
							Vector2D(m[0][1], m[1][1]));
		}

		inline Matrix3D ScaleY( float scale )
		{
			return Matrix3D(Vector2D(m[0][0]	, m[1][0]),
							Vector2D(m[0][1], m[1][1] * scale));
		}

		inline Matrix3D Translation( float x, float y )
		{
			x;
			y;
		}

		inline Matrix3D Translation( Vector2D& t )
		{
			t;
		}
	};
}

#endif