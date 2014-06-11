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
	strings[26] = '0'; // 
	strings[27] = '0'; // 
	strings[28] = '0'; // 
	strings[29] = '0'; //
}

DrawThing::~DrawThing(void)
{
	delete [] strings;
}

void DrawThing::draw(Core::Graphics& g)
{
	g.SetColor(RGB(255,255,0)); // YELLOW
	g.DrawString(10, 5, "Press 1, 2, or 3 to change the wall type");
	std::stringstream ss;
	ss << "Current wall type is : " << strings[0];
	g.DrawString(10, 20, ss.str().c_str());
	g.DrawString(10, 35, "Move the ship with the arrow or WASD keys");
	g.DrawString(10, 50, "Fire a missle with the left mouse button or spacebar");

	ss.str(std::string());
	ss << "FRAMES PER SECOND: " << strings[16];
	g.DrawString(10, 65, ss.str().c_str());

	ss.str(std::string());
	ss << "SECONDS PER FRAME: " << strings[17];
	g.DrawString(10, 80, ss.str().c_str());
	
	ss.str(std::string());
	ss << "Shots Fired: " << strings[18];
	g.DrawString(10, 95, ss.str().c_str());
	
	ss.str(std::string());
	ss << "Enemies Destroyed: " << strings[19];
	g.DrawString(10, 110, ss.str().c_str());
	

	ss.str(std::string());
	ss << "Ship position: (" << strings[1] << "\t," << strings[2] << ")";
	g.DrawString(10, 140, ss.str().c_str());
	ss.str(std::string());
	ss << "Ship velocity: (" << strings[3] << "\t," << strings[4] << ")";
	g.DrawString(10, 155, ss.str().c_str());
	ss.str(std::string());
	ss << "Ship matrix: ";
	g.DrawString(10, 170, ss.str().c_str());
	
	ss.str(std::string());
	ss << "( " ;
	g.DrawString(10, 185, ss.str().c_str());
	ss.str(std::string());
	ss << strings[5];
	g.DrawString(35, 185, ss.str().c_str());
	ss.str(std::string());
	ss << strings[6];
	g.DrawString(85, 185, ss.str().c_str());
	ss.str(std::string());
	ss << strings[7];
	g.DrawString(135, 185, ss.str().c_str());
	
	ss.str(std::string());
	ss << strings[8];
	g.DrawString(35, 200, ss.str().c_str());
	ss.str(std::string());
	ss << strings[9];
	g.DrawString(85, 200, ss.str().c_str());
	ss.str(std::string());
	ss << strings[10];
	g.DrawString(135, 200, ss.str().c_str());
	
	ss.str(std::string());
	ss << strings[11];
	g.DrawString(35, 215, ss.str().c_str());
	ss.str(std::string());
	ss << strings[12];
	g.DrawString(85, 215, ss.str().c_str());
	ss.str(std::string());
	ss << strings[13];
	g.DrawString(135, 215, ss.str().c_str());

	ss << "Mouse position: (" << strings[14] << "," << strings[15] << ")";
	g.DrawString(10, 230, ss.str().c_str());
	ss.str(std::string());

	//ss << "temp: (" << strings[16] << "," << strings[17] << "," << strings[18] << "," << strings[19] << "," << strings[20] << "," << strings[21] << "," << strings[22] << ")";
	//g.DrawString(10, 170, ss.str().c_str());
	//ss.str(std::string());
/*
	ss << "temp: (" << strings[22] << "-" << strings[23] << ")";
	g.DrawString(10, 170, ss.str().c_str());
	ss.str(std::string());*/
}

std::string DrawThing::floatToString(float f)
{
	std::stringstream ss;
	ss << floor(f * 1000) / 1000;
	return ss.str();
}

std::string DrawThing::intToString(int i)
{
	std::stringstream ss;
	ss << floor(i * 1000) / 1000;
	return ss.str();
}

void DrawThing::setDouble(int index, double d)
{
	std::stringstream ss;
	ss << floor(d * 1000) / 1000;
	strings[index] = ss.str();
}

void DrawThing::setFloat(int index, float f)
{
	strings[index] = floatToString(f);
}

void DrawThing::setInt(int index, int i)
{
	strings[index] = intToString(i);
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

void DrawThing::setFPS(float fps)
{
	strings[16] = floatToString(fps);
}

void DrawThing::setSPF(float spf)
{
	strings[17] = floatToString(spf);
}


void DrawThing::setShotsFired(int shots)
{
	strings[18] = intToString(shots);
}

void DrawThing::setEnemiesDestroyed(int enemyCount)
{
	strings[19] = intToString(enemyCount);
}