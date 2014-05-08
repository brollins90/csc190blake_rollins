#include "RenderUI.h"
#include "Engine.h"
#include "Vector2D.h"
using std::cout;
using std::endl;
using Engine::Vector2D;
using Engine::Matrix2D;

Vector2D leftVector, rightVector, resultVector;

void myBasicVectorEquationCallback(const BasicVectorEquationInfo& data)
{
	leftVector.x = (data.scalar1 * data.x1);
	rightVector.x = (data.scalar2 * data.x2);
	leftVector.y = (data.scalar1 * data.y1);
	rightVector.y = (data.scalar2 * data.y2);
	resultVector = (data.add) ? leftVector + rightVector : leftVector - rightVector;
}

Vector2D orignalVector, normalVector, cwPerpendicularVector, ccwPerpendicularVector;

void myPerpendicularDataCallback(const PerpendicularData& data)
{
	orignalVector.x = data.x;
	orignalVector.y = data.y;
	normalVector = orignalVector.Normalize();
	cwPerpendicularVector = orignalVector.PerpCW();
	ccwPerpendicularVector = orignalVector.PerpCCW();
}

Vector2D leP, leN, leD;

void myLineEquationDataCallback(const LineEquationData& data)
{
	// TODO
	leD.x = data.d;
	leN.x = data.n_i;
	leN.y = data.n_j;
	leP.x = data.p_x;
}

Vector2D vector1, vector2, projectionVector, rejectionVector;

void myDotProductDataCallback(const DotProductData& data)
{
	vector1.x = data.v1i;
	vector1.y = data.v1j;
	vector2.x = data.v2i;
	vector2.y = data.v2j;
	
	Vector2D& left = (data.projectOntoLeftVector) ? vector1 : vector2;
	Vector2D& right = (data.projectOntoLeftVector) ? vector2 : vector1;

	projectionVector = (left.Normalize() * ((left.DotProduct(right)) / left.Length()));
	rejectionVector = right - projectionVector;
}

Vector2D aVector, bVector, aMinusBVector, aVectorLerpPortion, bVectorLerpPortion, lerpResultVector;

void myLerpDataCallback(const LerpData& data)
{
	aVector.x = data.a_i;
	aVector.y = data.a_j;
	bVector.x = data.b_i;
	bVector.y = data.b_j;
	aMinusBVector = bVector - aVector;
	aVectorLerpPortion = aVector * (1.0F - data.beta);
	bVectorLerpPortion = bVector * data.beta;
	lerpResultVector = Vector2D::LERP(aVector,bVector,data.beta);
}

Vector2D resultVector2, vBasic;
Matrix2D mBasic;
void myLinearTransformationCallback(const LinearTransformationData& data)
{
	// TODO
	mBasic.m[0][0] = data.m00; // a  | a  b |
	mBasic.m[0][1] = data.m01; // b  | c  d |
	mBasic.m[1][0] = data.m10; // c
	mBasic.m[1][1] = data.m11; // d
	vBasic.x = data.v0;
	vBasic.y = data.v1;

	resultVector2 = mBasic * vBasic;
}

Vector2D resultVectors;

void myAffineTransformationCallback(const AffineTransformationData& data)
{
	// TODO
	data.data;
}

Matrix2D lines, matrices, currentTransform;
int numLines = 0;

void myMatrixTransformCallback2D(const MatrixTransformData2D& data)
{
	// TODO
	data.rotate;
	data.scaleX;
	data.scaleY;
	data.selectedMatrix;
	data.translateX;
	data.translateY;
}

void myMatrixTransformCallback3D(const MatrixTransformData3D& data)
{
	// TODO
	data.rotateX;
	data.rotateY;
	data.rotateZ;
	data.scaleX;
	data.scaleY;
	data.scaleZ;
	data.selectedMatrix;
	data.translateX;
	data.translateY;
	data.translateZ;
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

	// Basic Matrix Multiply
	renderUI.setLinearTransformationData((float*)&resultVector2,
		myLinearTransformationCallback);

	// Affine Transformations
	renderUI.setAffineTransformationData((float*)&resultVectors,
		myAffineTransformationCallback);

	// Matrix Transformations
	renderUI.set2DMatrixVerticesTransformData((float*)&lines,
		numLines,
		(float*)&matrices,
		(float*)&currentTransform,
		myMatrixTransformCallback2D);

	

	if( ! renderUI.initialize(argc, argv))
		return -1;
	return renderUI.run();
}