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
	void draw( Core::Graphics& g );
	void setFloat(int index, float f);
	void setString(int index, std::string string);
};

#endif