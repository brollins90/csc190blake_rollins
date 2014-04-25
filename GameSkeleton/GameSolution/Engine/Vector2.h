
#ifndef VECTOR2_H
#define VECTOR2_H

struct Engine::Vector2
{
private:
public:
	float x, y;
	Engine::Vector2(float x = 0, float y = 0);

	friend std::ostream& operator<<(std::ostream& stream, const Vector2& right);
	// Conversion
	float operator[] (int size);
	friend Vector2 operator+(const Vector2& left, const Vector2& right);
	friend Vector2 operator-(const Vector2& left, const Vector2& right);
	friend Vector2 operator*(const Vector2& left, const Vector2& right);
	friend Vector2 operator/(const Vector2& left, const Vector2& right);
//	// float * Vector2
//	friend Vector2 operator*(const float& left, const Vector2& right);
//	// Vector2 * float
////	friend Vector2 operator*(const Vector2& left, const float& right);
//	// Vector2 / float
//	friend Vector2 operator/(const Vector2& left, const float& right);
//	// LERP
//	//friend Vector2 LERP(const Vector2& left, const Vector2& right, const float& scaler);
//	// o	float Length() 
//	float Length();
//	// o	float LengthSquared()
//	float LengthSquared();
//	// o	Normalized()
//	// o	PerpCW
//	// o	PerpCCW
//	// o	Dot
//	//friend float DotProduct(const Vector2& a, const Vector2& b);
//	// o	Cross
};

#endif
