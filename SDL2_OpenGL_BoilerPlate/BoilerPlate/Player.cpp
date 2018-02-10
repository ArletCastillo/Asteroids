#include "Player.hpp"
#include <SDL2/SDL_opengl.h>
#include <iostream>
using namespace std;

Player::Player() {
	base = Vector2(0, 0);
}

Player::Player(float _x, float _y) {
	base = Vector2(_x, _y);
}

void Player::moveBase(Vector2 _vector) {
	base.x += _vector.x; 
	base.y += _vector.y;
}

void Player::Thruster() {
	glBegin(GL_LINE_LOOP);
	glVertex2f(-6.0, -7.0);
	glVertex2f(6.0, -7.0);
	glVertex2f(0.0, -15.0);
	glEnd();
}

void Player::Render() {
	glLoadIdentity();
	glTranslatef(base.x, base.y, 0.0f);

	glBegin(GL_LINE_LOOP);
	glVertex2f(0.0, 20.0); 
	glVertex2f(12.0, -10.0); 
	glVertex2f(6.0, -4.0); 
	glVertex2f(-6.0, -4.0);
	glVertex2f(-12.0, -10.0);

	cout << base.x << "," << base.y << endl;
	glEnd();

	if (activateThruster == true) {
		Thruster();
	}

	
	/*
	 *  glVertex2f(50.0 + base.x, 50.0 + base.y); //primer cuadrante
	 *  glVertex2f(50.0+base.x, -50.0+base.y); // cuarto cuadrante
	 *  glVertex2f(-50.0+base.x, -50.0+base.y); //tercer cuadrante
	 *  glVertex2f(-50.0+base.x, 50.0+base.y); //segundo cuadrante
	 */
}