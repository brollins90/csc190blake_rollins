#ifndef DRAWTHING_H
#define DRAWTHING_H

#include "Engine.h"
#include "Core.h"
#include <sstream>

class DrawThing
{
private:
	std::string* strings;
public:
	DrawThing(void);
	~DrawThing(void);

	void draw(Core::Graphics& g);
	std::string floatToString(float f);
	std::string intToString(int i);
	void setDouble(int index, double d);
	void setFloat(int index, float f);
	void setInt(int index, int i);
	void setMousePos(int mouseX, int mouseY);
	void setShipMatrix(Engine::Matrix3D m);
	void setString(int index, std::string string);
};

#endif