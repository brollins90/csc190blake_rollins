#ifndef DRAW_THING_H
#define DRAW_THING_H

#include "Engine.h"
#include "Core.h"
#include "DebugMemory.h"
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
	void setFPS(float fps);
	void setSPF(float spf);
	void setShotsFired(int shots);
	void setEnemiesDestroyed(int enemyCount);
};

#endif