#include "RenderUI.h"
#include "Engine.h"
#include "Vector2D.h"
using std::cout;
using std::endl;
//using Engine::Vector2;

Engine::Vector2D leftVector, rightVector, resultVector;

void myBasicVectorEquationCallback(const BasicVectorEquationInfo& data)
{
	leftVector.x = (data.scalar1 * data.x1);
	rightVector.x = (data.scalar2 * data.x2);
	leftVector.y = (data.scalar1 * data.y1);
	rightVector.y = (data.scalar2 * data.y2);
	if (data.add)
	{
		resultVector.x = (leftVector + rightVector).x;
		resultVector.y = (leftVector + rightVector).y;
	}
	else
	{
		resultVector.x = (leftVector - rightVector).x;
		resultVector.y = (leftVector - rightVector).y;
	}
}

Engine::Vector2D orignalVector, normalVector, cwPerpendicularVector, ccwPerpendicularVector;

void myPerpendicularDataCallback(const PerpendicularData& data)
{
	orignalVector.x = data.x;
	orignalVector.y = data.y;
	normalVector = orignalVector.Normalize();
	cwPerpendicularVector = orignalVector.PerpCW();
	ccwPerpendicularVector = orignalVector.PerpCCW();

}

Engine::Vector2D leP, leN, leD;

void myLineEquationDataCallback(const LineEquationData& data)
{
	// TODO
	leD.x = data.d;
	leN.x = data.n_i;
	leN.y = data.n_j;
	leP.x = data.p_x;
}

Engine::Vector2D vector1, vector2, projectionVector, rejectionVector;

void myDotProductDataCallback(const DotProductData& data)
{
	vector1.x = data.v1i;
	vector1.y = data.v1j;
	vector2.x = data.v2i;
	vector2.y = data.v2j;
	
	Engine::Vector2D& left = (data.projectOntoLeftVector) ? vector1 : vector2;
	Engine::Vector2D& right = (data.projectOntoLeftVector) ? vector2 : vector1;

	projectionVector = (left.Normalize() * ((left.DotProduct(right)) / left.Length()));
	rejectionVector = right - projectionVector;
}

Engine::Vector2D aVector, bVector, aMinusBVector, aVectorLerpPortion, bVectorLerpPortion, lerpResultVector;

void myLerpDataCallback(const LerpData& data)
{
	aVector.x = data.a_i;
	aVector.y = data.a_j;
	bVector.x = data.b_i;
	bVector.y = data.b_j;
	aMinusBVector = bVector - aVector;
	aVectorLerpPortion = aVector * (1.0F - data.beta);
	bVectorLerpPortion = bVector * data.beta;
	lerpResultVector = aVectorLerpPortion + bVectorLerpPortion;
}


int main(int argc, char* argv[])
{
	Engine::Init();

	RenderUI renderUI;

	// Vector Basics
	renderUI.setBasicVectorEquationData(myBasicVectorEquationCallback,
		(float*)&leftVector,
		(float*)&rightVector,
		(float*)&resultVector);

	// Perpendiculars
	renderUI.setPerpendicularData((float*)&orignalVector,
		(float*)&normalVector,
		(float*)&cwPerpendicularVector,
		(float*)&ccwPerpendicularVector,
		myPerpendicularDataCallback);

	// Line Equation
	renderUI.setLineEquationData((float*)&leP,
		(float*)&leN,
		(float*)&leD,
		myLineEquationDataCallback);

	// Dot Product
	renderUI.setDotProductData((float*)&vector1,
		(float*)&vector2,
		(float*)&projectionVector,
		(float*)&rejectionVector,
		myDotProductDataCallback);

	// LERP
	renderUI.setLerpData((float*)&aVector,
		(float*)&bVector,
		(float*)&aMinusBVector,
		(float*)&aVectorLerpPortion,
		(float*)&bVectorLerpPortion,
		(float*)&lerpResultVector,
		myLerpDataCallback);

	if( ! renderUI.initialize(argc, argv))
		return -1;
	return renderUI.run();
}