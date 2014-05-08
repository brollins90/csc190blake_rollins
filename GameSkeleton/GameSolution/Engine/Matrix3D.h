#ifndef MATRIX3D_H
#define MATRIX3D_H
#include "Vector2D.h"

namespace Engine
{
	struct Matrix3D
	{
	public:
		Engine::Matrix3D(void)
		{

		}
		
		Engine::Matrix3D(Vector2D& v1, Vector2D& v2)
		{
			v1;
			v2;
		}

		inline Matrix3D operator* (const Matrix3D& other)
		{
			other;
		}

		inline Matrix3D operator* (const Vector2D& other)
		{
			other;
		}

		inline Matrix3D Rotation( float angle )
		{
			angle;
		}

		inline Matrix3D Scale( float scale )
		{
			scale;
		}

		inline Matrix3D ScaleX( float scale )
		{
			scale;
		}

		inline Matrix3D ScaleY( float scale )
		{
			scale;
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