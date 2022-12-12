#pragma once
#include "Header.h"
class Car;
class Bullet :public Car
{
private:
	float x3;
	float y3;
	char last;
	char flag;
	int r;
public:
	int bounce;
	bool dec;
	void set_x3(int a)
	{
		x3 = a;
	}
	int get_x3()
	{
		return x3;
	}
	void set_y3(int a)
	{
		y3 = a;
	}
	int get_y3()
	{
		return y3;
	}
	void set_last(char a)
	{
		last = a;
	}
	bool get_last()
	{
		return last;
	}
	void set_flag(char a)
	{
		flag = a;
	}
	bool get_flag()
	{
		return flag;
	}
	void set_r(int a)
	{
		r = a;
	}
	void drawBullet()
	{

		DrawCircle(x3 + 10, y3 + 10, r, colors[MISTY_ROSE]);
	}
	void MoveBullet()
	{
		if (last == 'r')
		{
			x3 += 1;
		}
		if (last == 'l')
		{
			x3 -= 1;
		}
		if (last == 'u')
		{
			y3 += 1;

		}
		if (last == 'd')
		{
			y3 -= 1;
		}
	}
};
