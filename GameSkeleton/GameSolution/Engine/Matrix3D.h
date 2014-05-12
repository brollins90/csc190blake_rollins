#ifndef MATRIX3D_H
#define MATRIX3D_H
#include "Vector2D.h"

namespace Engine
{
	struct Matrix3D
	{
	public:
		float m[9];
		// __        __
		// | 0  1  2  |
		// | 3  4  5  |
		// | 6  7  8  |
		// __        __

		Engine::Matrix3D(void)
		{
			m[0] = 1; m[1] = 0; m[2] = 0;
			m[3] = 0; m[4] = 1; m[5] = 0;
			m[6] = 0; m[7] = 0; m[8] = 1;
		}

		Engine::Matrix3D(const float f0, const float f1, const float f2, const float f3, const float f4, const float f5, const float f6, const float f7, const float f8)
		{
			m[0] = f0; m[1] = f1; m[2] = f2;
			m[3] = f3; m[4] = f4; m[5] = f5;
			m[6] = f6; m[7] = f7; m[8] = f8;
		}
		
		Engine::Matrix3D(const Vector2D& v1, const Vector2D& v2)
		{
			m[0] = v1.x; m[1] = v2.x, m[2] = 0;
			m[3] = v1.y; m[4] = v2.y; m[5] = 0;
			m[6] = 0;    m[7] = 0;    m[8] = 1;
		}
		
		Engine::Matrix3D(const Vector3D& v1, const Vector3D& v2)
		{
			m[0] = v1.x; m[1] = v2.x, m[2] = 0;
			m[3] = v1.y; m[4] = v2.y; m[5] = 0;
			m[6] = 0;    m[7] = 0;    m[8] = 1;
		}

		inline Matrix3D operator* (const Matrix3D& other)
		{
			return Matrix3D(
				m[0] * other.m[0] + m[1] * other.m[3], m[0] * other.m[1] + m[1] * other.m[4], m[0] * other.m[2] + m[1] * other.m[5] + m[2], 
				m[3] * other.m[0] + m[4] * other.m[3], m[3] * other.m[1] + m[3] * other.m[5], m[3] * other.m[2] + m[4] * other.m[5] + m[5], 
				0, 0, 1);
		}

		inline Vector2D operator* (const Vector2D& other)
		{
			return Vector2D((m[0] * other.x) + (m[1] * other.y) + m[2], 
							(m[3] * other.x) + (m[4] * other.y) + m[5]);
		}

		inline Vector3D operator* (const Vector3D& other)
		{
			return Vector3D((m[0] * other.x) + (m[1] * other.y) + m[2], 
							(m[3] * other.x) + (m[4] * other.y) + m[5],
							1);
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
			return Matrix3D(m[0] * scale,	m[1],			m[2],
							m[3],			m[4] * scale,	m[5],
							m[6],			m[7],			m[8]);
		}

		inline Matrix3D ScaleX( float scale )
		{
			return Matrix3D(m[0] * scale,	m[1],			m[2],
							m[3],			m[4],			m[5],
							m[6],			m[7],			m[8]);
		}

		inline Matrix3D ScaleY( float scale )
		{
			return Matrix3D(m[0],			m[1],			m[2],
							m[3],			m[4] * scale,	m[5],
							m[6],			m[7],			m[8]);
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