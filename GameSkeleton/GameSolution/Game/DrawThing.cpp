
#include "DrawThing.h"

DrawThing::DrawThing(void)
{
	strings = new std::string[10];
	strings[0] = "WRAP";
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
	g.DrawString(10, 5, "Press 1, 2, or 3 to change the wall type");
	std::stringstream ss;
	ss << "Current wall type is : " << strings[0];
	g.DrawString(10, 15, ss.str().c_str());
	ss.str(std::string());
	ss << "Ship position: (" << strings[1] << "," << strings[2] << ")";
	g.DrawString(10, 25, ss.str().c_str());
	ss.str(std::string());
	ss << "Ship velocity: (" << strings[3] << "," << strings[4] << ")";
	g.DrawString(10, 35, ss.str().c_str());
	ss.str(std::string());

}
void DrawThing::setString(int index, std::string string)
{
	strings[index] = string;
}

void DrawThing::setFloat(int index, float f)
{
	std::stringstream ss;
	ss << f;
	strings[index] = ss.str();
}