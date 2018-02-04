#include "Player.hpp"
#include "Colors.hpp"
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

void Player::Render() {
	//glClearColor(0.1f, 0.1f, 0.15f, 1.0f)
	Colors c;
	glClearColor(c.orange().r, c.orange().g, c.orange().b, c.orange().a);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glVertex2f(50.0 + base.x, 50.0 + base.y); 
	glVertex2f(50.0+base.x, -50.0+base.y);
	glVertex2f(-50.0+base.x, -50.0+base.y);
	glVertex2f(-50.0+base.x, 50.0+base.y);
	glEnd();
	
}