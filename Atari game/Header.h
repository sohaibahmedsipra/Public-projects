#pragma once
#include "util.h"
class Car
{
protected:
	float x;
	float xI;
	float yI;
	int type;
	int score;
	int lives;
	
public:
	Car()
	{
		x = 100;
		xI = 500;
		yI = 515;
		type = 1;
		score = 0;
		lives = 0;
	}
	void set_type(int a)
	{

	}
	void set_xI(int a)
	{
		xI = a;
	}
	void set_yI(int a)
	{
		yI = a;
	}
	int get_xI()
	{
		return xI;
	}
	int get_yI()
	{
		return yI;
	}
	void set_lives_x(int a)
	{
		x = a;
	}
	void setlives(int a)
	{
		lives += a;
	}
	int get_lives()
	{
		return lives;
	}
	void setscore(int a)
	{
		score += a;
	}
	void drawCar() {
		if(type==1)
			DrawSquare(xI, yI, 30, colors[BLACK]);
		if (type == 2)
			DrawCircle(xI, yI, 20, colors[ORANGE]);
		else
		{
			DrawSquare(xI, yI, 30, colors[BLACK]);
			DrawCircle(xI, yI, 20, colors[ORANGE]);

		}
		glutPostRedisplay();
	}
	void drawscore() {
		string a;
		a = to_string(score);
		DrawString(x - 60, 750, "S: ", colors[WHITE]);
		DrawString(x , 750, a, colors[WHITE]);
		DrawString(x + 100, 750, "L: ", colors[WHITE]);
		DrawString(x + 160, 750, to_string(lives), colors[WHITE]);
	}
	void newgame()
	{
		lives = 10;
		score = 0;
	}
};
