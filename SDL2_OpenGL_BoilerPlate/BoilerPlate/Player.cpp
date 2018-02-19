#include "Player.hpp"
#include <SDL2/SDL_opengl.h>

Player::Player() {
	base = Vector2(0, 0);
	angle = 0.0f;
	//coordenates for the ship
	shipContainer.push_back(Vector2(0.0, 20.0));
	shipContainer.push_back(Vector2(12.0, -10.0));
	shipContainer.push_back(Vector2(6.0, -4.0));
	shipContainer.push_back(Vector2(-6.0, -4.0));
	shipContainer.push_back(Vector2(-12.0, -10.0));
	//coordenates for the thruster
	thrusterContainer.push_back(Vector2(-6.0, -7.0));
	thrusterContainer.push_back(Vector2(6.0, -7.0));
	thrusterContainer.push_back(Vector2(0.0, -15.0));
}

void Player::Thruster() {
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < thrusterContainer.size(); i++)
		glVertex2f(thrusterContainer[i].x, thrusterContainer[i].y);
	glEnd();
}

void Player::Render() {
	glLoadIdentity();
	glTranslatef(base.x, base.y, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
	for (int i=0;i<shipContainer.size();i++)
		glVertex2f(shipContainer[i].x, shipContainer[i].y);
	glEnd();

	if (activateThruster == true) {
		Thruster();
	}

}