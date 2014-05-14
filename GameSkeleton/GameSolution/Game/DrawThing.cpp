
#include "DrawThing.h"

DrawThing::DrawThing(void)
{
	strings = new std::string[20];
	strings[0] = "WRAP"; // Wall type
	strings[1] = '0'; // Ship pos x
	strings[2] = '0'; // Ship pos y
	strings[3] = '0'; // Ship vel x
	strings[4] = '0'; // Ship vel y
	strings[5] = '0'; // Ship m 0
	strings[6] = '0'; // Ship m 1
	strings[7] = '0'; // Ship m 2
	strings[8] = '0'; // Ship m 3
	strings[9] = '0'; // Ship m 4
	strings[10] = '0'; // Ship m 5
	strings[11] = '0'; // Ship m 6
	strings[12] = '0'; // Ship m 7
	strings[13] = '0'; // Ship m 8
	strings[14] = '0'; // 
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
	g.DrawString(10, 20, ss.str().c_str());
	ss.str(std::string());
	ss << "Ship position: (" << strings[1] << "," << strings[2] << ")";
	g.DrawString(10, 35, ss.str().c_str());
	ss.str(std::string());
	ss << "Ship velocity: (" << strings[3] << "," << strings[4] << ")";
	g.DrawString(10, 50, ss.str().c_str());
	ss.str(std::string());
	ss << "Ship matrix: ";
	g.DrawString(10, 65, ss.str().c_str());
	ss.str(std::string());
	ss << "( " << strings[5] << "   " << strings[6] << "   " << strings[7];
	g.DrawString(10, 80, ss.str().c_str());
	ss.str(std::string());
	ss << "  " << strings[8] << "   " << strings[9] << "   " << strings[10];
	g.DrawString(10, 95, ss.str().c_str());
	ss.str(std::string());
	ss << "  " << strings[11] << "   " << strings[12] << "   " << strings[13] << " )";
	g.DrawString(10, 110, ss.str().c_str());
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

void setShipMatrix(Engine::Matrix3D) 
{
	
}