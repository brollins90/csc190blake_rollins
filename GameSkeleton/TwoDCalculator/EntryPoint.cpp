#include "RenderUI.h"
#include "Engine.h"
#include "Vector2D.h"
using std::cout;
using std::endl;
//using Engine::Vector2;

Engine::Vector2D basicLeft, basicRight, basicResult;

void myBasicVectorEquationCallback(const BasicVectorEquationInfo& data)
{
	basicLeft.x = (data.scalar1 * data.x1);
	basicRight.x = (data.scalar2 * data.x2);
	basicLeft.y = (data.scalar1 * data.y1);
	basicRight.y = (data.scalar2 * data.y2);
	if (data.add)
	{
		basicResult.x = (basicLeft + basicRight).x;
		basicResult.y = (basicLeft + basicRight).y;
	}
	else
	{
		basicResult.x = (basicLeft - basicRight).x;
		basicResult.y = (basicLeft - basicRight).y;
	}
	//cout << "lx: " << basicLeft.x << endl;
	//cout << "ly: " << basicLeft.y << endl;
	//cout << "rx: " << basicRight.x << endl;
	//cout << "ry: " << basicRight.y << endl;
	//cout << "resx: " << basicResult.x << endl;
	//cout << "resy: " << basicResult.y << endl;
}

Engine::Vector2D perpOrig, perpNormal, perpCW, perpCCW;

void myPerpendicularDataCallback(const PerpendicularData& data)
{
	// TODO
	perpOrig.x = data.x;
	perpOrig.y = data.y;

}

Engine::Vector2D leN;
float leP, leD;

void myLineEquationDataCallback(const LineEquationData& data)
{
	// TODO
	leD = data.d;
	leN.x = data.n_i;
	leN.y = data.n_j;
	leP = data.p_x;
}

Engine::Vector2D dot1, dot2, dotProj, dotRej;

void myDotProductDataCallback(const DotProductData& data)
{
	// TODO
	data.projectOntoLeftVector;
	dot1.x = data.v1i;
	dot1.y = data.v1j;
	dot2.x = data.v2i;
	dot2.y = data.v2j;
}

Engine::Vector2D lerpA, lerpB, lerpAPart, lerpBPart, lerpRes, lerpMinB;

void myLerpDataCallback(const LerpData& data)
{
	// TODO
	data.a_i;
	data.a_j;
	data.beta;
	data.b_i;
	data.b_j;
}


int main(int argc, char* argv[])
{
	Engine::Init();

	RenderUI renderUI;

	// Vector Basics
	renderUI.setBasicVectorEquationData(myBasicVectorEquationCallback,
		(float*)&basicLeft,
		(float*)&basicRight,
		(float*)&basicResult);

	// Perpendiculars
	renderUI.setPerpendicularData((float*)&perpOrig,
		(float*)&perpNormal,
		(float*)&perpCW,
		(float*)&perpCCW,
		myPerpendicularDataCallback);

	// Line Equation
	renderUI.setLineEquationData((float*)&leP,
		(float*)&leN,
		(float*)&leD,
		myLineEquationDataCallback);

	// Dot Product
	renderUI.setDotProductData((float*)&dot1,
		(float*)&dot2,
		(float*)&dotProj,
		(float*)&dotRej,
		myDotProductDataCallback);

	// LERP
	renderUI.setLerpData((float*)&lerpA,
		(float*)&lerpB,
		(float*)&lerpMinB,
		(float*)&lerpAPart,
		(float*)&lerpBPart,
		(float*)&lerpRes,
		myLerpDataCallback);

	if( ! renderUI.initialize(argc, argv))
		return -1;
	return renderUI.run();
}