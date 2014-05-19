#include "DrawThing.h"

DrawThing::DrawThing(void)
{
	strings = new std::string[30];
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
	strings[14] = '0'; // mouse x
	strings[15] = '0'; // mouse y
	strings[16] = '0'; // 
	strings[17] = '0'; // 
	strings[18] = '0'; // 
	strings[19] = '0'; // 
	strings[20] = '0'; // 
	strings[21] = '0'; // 
	strings[22] = '0'; // 
	strings[23] = '0'; // 
	strings[24] = '0'; // 
	strings[25] = '0'; //
}

DrawThing::~DrawThing(void)
{
	delete strings;
}

void DrawThing::draw(Core::Graphics& g)
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
	ss << "Mouse position: (" << strings[14] << "," << strings[15] << ")";
	g.DrawString(10, 125, ss.str().c_str());
	ss.str(std::string());
	ss << "temp: (" << strings[16] << "," << strings[17] << "," << strings[18] << "," << strings[19] << "," << strings[20] << "," << strings[21] << "," << strings[22] << ")";
	g.DrawString(10, 140, ss.str().c_str());
	ss.str(std::string());
}

std::string DrawThing::floatToString(float f)
{
	std::stringstream ss;
	ss << f;
	return ss.str();
}

std::string DrawThing::intToString(int i)
{
	std::stringstream ss;
	ss << i;
	return ss.str();
}

void DrawThing::setDouble(int index, double d)
{
	std::stringstream ss;
	ss << d;
	strings[index] = ss.str();
}

void DrawThing::setFloat(int index, float f)
{
	std::stringstream ss;
	ss << f;
	strings[index] = ss.str();
}

void DrawThing::setInt(int index, int i)
{
	std::stringstream ss;
	ss << i;
	strings[index] = ss.str();
}

void DrawThing::setMousePos(int x, int y)
{
	strings[14] = intToString(x);
	strings[15] = intToString(y);
}

void DrawThing::setShipMatrix(Engine::Matrix3D m) 
{
	strings[5] = floatToString(m.m[0]);
	strings[6] = floatToString(m.m[1]);
	strings[7] = floatToString(m.m[2]);
	strings[8] = floatToString(m.m[3]);
	strings[9] = floatToString(m.m[4]);
	strings[10] = floatToString(m.m[5]);
	strings[11] = floatToString(m.m[6]);
	strings[12] = floatToString(m.m[7]);
	strings[13] = floatToString(m.m[8]);
}

void DrawThing::setString(int index, std::string string)
{
	strings[index] = string;
}