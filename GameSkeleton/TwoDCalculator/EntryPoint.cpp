#include "RenderUI.h"
#include "Engine.h"
#include "Vector2.h"
using std::cout;
using std::endl;
//using Engine::Vector2;

Engine::Vector2 basicLeft(0,1), basicRight(2,3), basicResult(4,5);
//Vector2 left, right, results;

void myBasicVectorEquationCallback(const BasicVectorEquationInfo& data)
{
	basicLeft.x = data.x1;
	basicRight.x = data.x2;
	basicLeft.y = data.y1;
	basicRight.y = data.y2;
	basicResult.x = data.scalar1;
	basicResult.y = data.scalar2;
	cout << "lx: " << basicLeft.x << endl;
	cout << "ly: " << basicLeft.y << endl;
	cout << "rx: " << basicRight.x << endl;
	cout << "ry: " << basicRight.y << endl;
	cout << "resx: " << basicResult.x << endl;
	cout << "resy: " << basicResult.y << endl;
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