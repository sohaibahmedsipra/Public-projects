//============================================================================
// Name        : i21_1114_Sohaib_FP_P.cpp
// Author      : FAST SE Department
// Version     : 01
// Copyright   : (c) Reserved
// Description : Basic 2D game
//============================================================================

#ifndef Compound_CPP_
#define Compound_CPP_
#include "util.h"
#include <iostream>
#include <conio.h>
#include<string>
#include<time.h>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include "Header.h"
#include "Bullet.h"
using namespace std;
Car P1, P2;
Bullet b1, b2;
bool global = false;
bool global_1 = false;
bool collision = false;
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int i = 0;
int j = 0;	//for bullets

char last = 'r';

void bullet_collide()
{
	if (b1.get_x3() == 20 || b1.get_x3() == 1000 || b1.get_y3() == 40 || b1.get_y3() == 700)
	{
		if (b1.get_x3() == 1000)
		{
			b1.set_last('l');
		}
		if (b1.get_x3() == 20)
		{
			b1.set_last('r');
		}
		if (b1.get_y3() == 40)
		{
			b1.set_last('u');
		}
		if (b1.get_y3() == 700)
		{
			b1.set_last('d');
		}
		b1.bounce++;
	}
	if (b2.get_x3() == 20 || b2.get_x3() == 1000 || b2.get_y3() == 40 || b2.get_y3() == 700)
	{
		if (b2.get_x3() == 1000)
		{
			b2.set_last('l');
		}
		if (b2.get_x3() == 20)
		{
			b2.set_last('r');
		}
		if (b2.get_y3() == 40)
		{
			b2.set_last('u');
		}
		if (b2.get_y3() == 700)
		{
			b2.set_last('d');
		}
		b2.bounce++;
	}
	if ((b1.get_x3() >= 545 && b1.get_x3() <= 550) && (b1.get_x3() >= 300 && b1.get_x3() <= 480))
	{
		b1.bounce = 4;
	}
	if ((b2.get_x3() >= 545 && b2.get_x3() <= 550) && (b2.get_x3() >= 300 && b2.get_x3() <= 480))
	{
		b2.bounce = 4;
	}
	if (b1.dec == true && ((b1.get_x3() < P2.get_xI() + 50) && (b1.get_x3() > P2.get_xI())) && ((b1.get_y3() < P2.get_yI() + 30) && (b1.get_y3() > P2.get_yI())))
	{
		P2.setlives(-1);
		P1.setscore(100);
		b1.dec = false;
		b1.bounce = 4;
	}
	if (b2.dec == true && ((b2.get_x3() < P1.get_xI() + 50) && (b2.get_x3() > P1.get_xI())) && ((b2.get_y3() < P1.get_yI() + 30) && (b2.get_y3() > P1.get_yI())))
	{
		P1.setlives(-1);
		P2.setscore(100);
		b2.dec = false;
		b2.bounce = 4;

	}
}
void collide()
{
	if (P1.get_xI() == P2.get_xI() && P1.get_yI() == P2.get_yI())
	{
		srand(time(0));
		int temp1 = rand() % 500 + 50;
		int temp2 = rand() % 500 + 50;
		int temp3 = rand() % 500 + 50;
		int temp4 = rand() % 500 + 50;
		while (temp1 % 10 != 0)
		{
			temp1 = rand() % 500 + 50;
		}
		while (temp2 % 10 != 0)
		{
			temp2 = rand() % 500 + 50;
		}
		while (temp3 % 10 != 0)
		{
			temp3 = rand() % 500 + 50;
		}
		while (temp4 % 10 != 0)
		{
			temp4 = rand() % 500 + 50;
		}
		P1.set_xI(temp3); P1.set_xI(temp4); P2.set_xI(temp1); P2.set_yI(temp2);
		P2.setlives(-1);
		P2.setscore(100);
		P1.setlives(-1);
		P1.setscore(100);

	}
}


bool flag = true;
void moveCar() {

	if (P1.get_xI() > 0 && flag) {
		P1.set_xI(-0.1);
		cout << "going left";
		if (P1.get_xI() < 30)
			flag = false;

	}
	/*else if (xI < 1010 && !flag) {
		cout << "go right";
		xI += 0.1;
		if (xI > 900)
			flag = true;
	}*/
}

void Exitscreen()
{
	glClearColor(0.51/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	//glRasterPos3f(0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	DrawString(400, 700, "THANK YOU FOR PLAYING\"COMPOUND\"", colors[MISTY_ROSE]);
	//glutKeyboardFunc(exitkey);
	glutSwapBuffers(); // do not modify this line..
	glutPostRedisplay();
}
void settings()
{
	glClearColor(0.51/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	//glRasterPos3f(0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	DrawString(525, 500, "1 - SQUARE", colors[MISTY_ROSE]);
	DrawString(550, 470, "2 - CIRCLE", colors[MISTY_ROSE]);
	DrawString(550, 440, "3 - TANK", colors[MISTY_ROSE]);
	//glutKeyboardFunc(exitkey);
	glutSwapBuffers(); // do not modify this line..
	glutPostRedisplay();
}
void winP2()
{
	glClearColor(0.51/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	if (P1.get_lives() > P2.get_lives())
	{
		DrawString(400, 700, "PLAYER ONE HAS WON THE MATCH!!!", colors[MISTY_ROSE]);

	}
	else
	{
		DrawString(400, 700, "PLAYER TWO HAS WON THE MATCH!!!", colors[MISTY_ROSE]);
	}
	DrawString(400, 700, "PRESS X FOR REMATCH!!!", colors[MISTY_ROSE]);

	glutSwapBuffers(); // do not modify this line..
	glutPostRedisplay();
}
bool endgame = false;
bool resume=true;
void GameDisplay()
{
	if (resume == true)
	{
		P1.set_lives_x(100);
		P2.set_lives_x(700);

		// set the background color using function glClearColor.
		// to change the background play with the red, green and blue values below.
		// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

		glClearColor(0.51/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear(GL_COLOR_BUFFER_BIT); //Update the colors

		//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
		DrawLine(550, 300, 550, 480, 10, colors[MISTY_ROSE]);
		//DrawLine(50, 50, 50, 80, 10, colors[MISTY_ROSE]);
		DrawLine(20, 700, 1000, 700, 10, colors[MISTY_ROSE]);
		DrawLine(20, 40, 1000, 40, 10, colors[MISTY_ROSE]);
		DrawLine(20, 40, 20, 700, 10, colors[MISTY_ROSE]);
		DrawLine(1000, 40, 1000, 700, 10, colors[MISTY_ROSE]);
		P1.drawscore();
		P2.drawscore();

		P1.drawCar();
		P2.drawCar();
		if (global && b1.bounce <= 3)
		{

			if (i == 0)
			{
				b1.set_x3(P1.get_xI() + 15);
				b1.set_y3(P1.get_yI() + 15);
				cout << b1.get_x3() << " " << b1.get_y3();
				i++;
			}

			b1.drawBullet();
			b1.MoveBullet();


			//glutPostRedisplay();
		}
		if (global_1 && b2.bounce <= 3)
		{
			if (j == 0)
			{
				b2.set_x3(P2.get_xI() + 15);
				b2.set_y3(P2.get_yI() + 15);
				cout << b2.get_x3() << " " << b2.get_y3();
				j++;
			}

			b2.drawBullet();
			b2.MoveBullet();


			//glutPostRedisplay();
		}
		if (P1.get_lives() == 0 || P2.get_lives() == 0)
		{
			endgame = true;
		}
		if (endgame == true)
		{
			glutDisplayFunc(winP2);
		}
		bullet_collide();
		collide();
		glutSwapBuffers(); // do not modify this line..

	}
	
}

void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {

		Exitscreen();
		//glutKeyboardFunc(mykey);

		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
	{
		b1.set_r ( 5);
		//DrawLine(50, 50, 50, 80, 10, colors[MISTY_ROSE]);
		global = true;
		i = 0;
		//do something if b is pressed
		cout << "b pressed" << endl << b1.get_flag();
		b1.bounce = 0;
		b1.dec = true;

	}
	if (key == 'p' || key == 'P')
	{
		resume = false;
	}
	if (key == 'r' || key == 'R')
	{
		resume = true;
	}
	if (key == '1')
	{
		P1.set_type(1);
		P2.set_type(1);
	}
	if (key == '2')
	{
		P1.set_type(2);
		P2.set_type(2);
	}
	if (key == '3')
	{
		P1.set_type(3);
		P2.set_type(3);
	}

	if (key == 'n' || key == 'N') //Key for placing the bomb
	{
		b1.set_r (10);
		//DrawLine(50, 50, 50, 80, 10, colors[MISTY_ROSE]);
		global = true;
		i = 0;
		//do something if b is pressed
		cout << "n pressed" << endl << b1.get_flag();
		b1.bounce = 0;
		b1.dec = true;

	}
	if (key == 'x' || key == 'X')
	{
		bool newg = true;
		if (newg == true)
		{
			P1.set_xI(400);
			P1.set_yI(415);
			P2.set_xI(500);
			P2.set_yI(515);
			newg = false;
		}
		P1.newgame();
		P2.newgame();
		glutDisplayFunc(GameDisplay);
	}
	if (key == 32)
	{
		b2.bounce = 0;
		global_1 = true;
		j = 0;
		//do something if space is pressed
		cout << "space pressed" << endl << b2.get_flag();
		b2.dec = true;

	}
	if (key == 'a' /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when a key is pressed...
		if (!(((P2.get_xI() >= 545 && P2.get_xI() <= 550) && (P2.get_yI() >= 300 && P2.get_yI() <= 480)) || (P2.get_xI() >= 20 && P2.get_xI() <= 25)))
		{
			P2.set_xI(P2.get_xI() - 10);

			b2.set_last('l');
		}
	}
	else if (key == 'd' /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		if (!(((P2.get_xI() >= 525 && P2.get_xI() <= 535) && (P2.get_yI() >= 300 && P2.get_yI() <= 480)) || (P2.get_xI() >= 980 && P2.get_xI() <= 1005)))
		{
			P2.set_xI(P2.get_xI() + 10);
			b2.set_last('r');

		}
	}
	else if (key == 'w'/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/)
	{
		if (!(((P2.get_xI() >= 535 && P2.get_xI() <= 545) && (P2.get_yI() >= 280 && P2.get_yI() <= 480)) || (P2.get_yI() >= 680 && P2.get_yI() <= 705)))
		{
			P2.set_yI(P2.get_yI() + 10);
			b2.set_last('u');

		}
	}
	else if (key == 's'/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		if (!(((P2.get_xI() >= 535 && P2.get_xI() <= 545) && (P2.get_yI() >= 300 && P2.get_yI() <= 480)) || (P2.get_yI() >= 40 && P2.get_yI() <= 45)))
		{
			P2.set_yI(P2.get_yI() - 10);
			b2.set_last('d');

		}

	}
	glutPostRedisplay();
	//glutSwapBuffers(); // do not modify this line..

}
/*
 * Main Canvas drawing function.
 * */
void Timer(int m) {

	// implement your functionality here
	//moveCar();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}


void MenuDisplay()
{

	glClearColor(0.51/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	//glRasterPos3f(0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	DrawString(400, 700, "WELCOME TO THE GAME \"COMPOUND\"", colors[MISTY_ROSE]);
	DrawString(525, 500, "X - To start the game", colors[MISTY_ROSE]);
	DrawString(550, 470, "H - Highscore", colors[MISTY_ROSE]);
	DrawString(550, 440, "P - PAUSE", colors[MISTY_ROSE]);
	DrawString(550, 410, "R - RESUME", colors[MISTY_ROSE]);
	DrawString(550, 380, "S - SETTINGS", colors[MISTY_ROSE]);
	DrawString(555, 350, "Esc - Exit", colors[MISTY_ROSE]);
	glutSwapBuffers(); // do not modify this line..
}



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {

	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		if (!(((P1.get_xI() >= 545 && P1.get_xI() <= 550) && (P1.get_yI() >= 300 && P1.get_yI() <= 480)) || (P1.get_xI() >= 20 && P1.get_xI() <= 25)))
		{
			P1.set_xI(P1.get_xI() - 10);
			b1.set_last('l');


		}
	}
	else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		if (!(((P1.get_xI() >= 525 && P1.get_xI() <= 535) && (P1.get_xI() >= 300 && P1.get_xI() <= 480)) || (P1.get_xI() >= 980 && P1.get_xI() <= 1005)))
		{
			P1.set_xI(P1.get_xI() + 10);
			b1.set_last('r');

		}
	}
	else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/)
	{
		if (!(((P1.get_xI() >= 535 && P1.get_xI() <= 545) && (P1.get_yI() >= 280 && P1.get_yI() <= 480)) || (P1.get_yI() >= 680 && P1.get_yI() <= 705)))
		{
			P1.set_yI(P1.get_yI() + 10);
			b1.set_last('u');

		}
	}
	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		if (!(((P1.get_xI() >= 535 && P1.get_xI() <= 545) && (P1.get_yI() >= 300 && P1.get_yI() <= 480)) || (P1.get_yI() >= 40 && P1.get_yI() <= 45)))
		{
			P1.set_yI(P1.get_yI() - 10);
			b1.set_last('d');

		}

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */





 /*
  * our gateway main function
  * */
int main(int argc, char* argv[]) {

	int width = 1250, height = 780; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(0, 0); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Compound by Sohaib Sipra"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	glutDisplayFunc(MenuDisplay); // tell library which function to call for drawing Canvas.

	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	//glutKeyboardFunc(mykey);
									 // This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);



	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* Compound_CPP_ */
