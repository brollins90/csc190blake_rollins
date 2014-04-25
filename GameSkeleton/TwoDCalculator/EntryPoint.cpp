#include "RenderUI.h"
#include "Engine.h"
#include "Vector2D.h"
using std::cout;
using std::endl;
//using Engine::Vector2;

Engine::Vector2D basicLeft(0,0), basicRight(0,0), basicResult(0,0);

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

int main(int argc, char* argv[])
{
	Engine::Init();

	RenderUI renderUI;

	renderUI.setBasicVectorEquationData(myBasicVectorEquationCallback,
		(float*)&basicLeft,
		(float*)&basicRight,
		(float*)&basicResult);

	if( ! renderUI.initialize(argc, argv))
		return -1;
	return renderUI.run();
}