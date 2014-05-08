#ifndef MATRIX2D_H
#define MATRIX2D_H
#include "Vector2D.h"

namespace Engine
{
	struct Matrix2D
	{
	public:
		Engine::Matrix2D(void)
		{

		}
		
		Engine::Matrix2D(Vector2D& v1, Vector2D& v2)
		{
			v1;
			v2;
		}

		inline Matrix2D operator* (const Matrix2D& other)
		{
			other;
		}

		inline Matrix2D operator* (const Vector2D& other)
		{
			other;
		}

		inline Matrix2D Rotation( float angle )
		{
			angle;
		}

		inline Matrix2D Scale( float scale )
		{
			scale;
		}

		inline Matrix2D ScaleX( float scale )
		{
			scale;
		}

		inline Matrix2D ScaleY( float scale )
		{
			scale;
		}
	};
}

#endif