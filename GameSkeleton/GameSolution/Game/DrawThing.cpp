
#include "DrawThing.h"

DrawThing::DrawThing(void)
{
	strings = new std::string[10];
	strings[0] = '0';
	strings[1] = '0';
	strings[2] = '0';
	strings[3] = '0';
	strings[4] = "BLAKE";
	strings[5] = '0';
	strings[6] = '0';
	strings[7] = '0';
	strings[8] = '0';
	strings[9] = '0';
}
DrawThing::~DrawThing(void)
{
	delete strings;
}
void DrawThing::draw( Core::Graphics& g )
{
	std::stringstream ss;
	ss << "One: " << strings[0];
	g.DrawString(10, 5, ss.str().c_str());
	ss.str(std::string());
	ss << "Two: " << strings[1];
	g.DrawString(10, 15, ss.str().c_str());
	ss.str(std::string());
	ss << "Three: " << strings[2];
	g.DrawString(10, 25, ss.str().c_str());
	ss.str(std::string());
	ss << "Four: " << strings[3];
	g.DrawString(10, 35, ss.str().c_str());
	ss.str(std::string());
	ss << "Five: " << strings[4];
	g.DrawString(10, 45, ss.str().c_str());
	ss.str(std::string());
	ss << "Six: " << strings[5];
	g.DrawString(10, 55, ss.str().c_str());
	ss.str(std::string());

}
void DrawThing::setString(int index, char* string)
{
	strings[index] = *string;
}

void DrawThing::setFloat(int index, float f)
{
	std::stringstream ss;
	ss << f;
	strings[index] = ss.str();
}