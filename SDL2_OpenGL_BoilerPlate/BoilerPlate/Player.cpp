#include "Player.hpp"
#include <SDL2/SDL_opengl.h>
#include <cmath>
#include "MathUtilities.hpp"

Player::Player() {
	base = Vector2(0, 0);
	angle = 0.0f;
}

Player::Player(float _x, float _y) {
	base = Vector2(_x, _y);
	angle = 0.0f;
}

<<<<<<< HEAD
void Player::wrap(float& vertex, float min, float max) {
=======
void Player::Wrap(float& vertex, float min, float max) {
>>>>>>> feature/v0.0.4
	if (vertex < min) {
		vertex = max - (min - vertex);
	}
	if (vertex > max) {
		vertex = min - (max - vertex);
	}
}

<<<<<<< HEAD
void Player::moveBase(Vector2 _vector) {
=======
void Player::Move_forward(){
>>>>>>> feature/v0.0.4
	maxWidth = 1136 / 2.0f;
	halfWidth = -1136 / 2.0f;

	maxHeight = 640 / 2.0f;
	halfHeight = -640 / 2.0f;

<<<<<<< HEAD
	base.x += _vector.x; 
	base.y += _vector.y;

	wrap(base.x, halfWidth, maxWidth);
	wrap(base.y, halfHeight, maxHeight);
}

void Player::thruster() {
=======
	MathUtilities realAngle;
	base += Vector2(8 * sin(realAngle.degToRad(angle)*-1), 8*cos(realAngle.degToRad(angle)));

	Wrap(base.x, halfWidth, maxWidth);
	Wrap(base.y, halfHeight, maxHeight);
}

void Player::Thruster() {
>>>>>>> feature/v0.0.4
	glBegin(GL_LINE_LOOP);
	glVertex2f(-6.0, -7.0);
	glVertex2f(6.0, -7.0);
	glVertex2f(0.0, -15.0);
	glEnd();
<<<<<<< HEAD
=======
}

void Player::Rotate_left() {
	angle += 5;
}

void Player::Rotate_right() {
	angle -= 5;
>>>>>>> feature/v0.0.4
}

void Player::Render() {
	glLoadIdentity();
	glTranslatef(base.x, base.y, 0.0f);
<<<<<<< HEAD

=======
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
>>>>>>> feature/v0.0.4
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.0, 20.0); 
	glVertex2f(12.0, -10.0); 
	glVertex2f(6.0, -4.0); 
	glVertex2f(-6.0, -4.0);
	glVertex2f(-12.0, -10.0);

<<<<<<< HEAD
	cout << base.x << "," << base.y << endl;
	glEnd();

	if (activateThruster == true) {
		thruster();
	}

	
	/*
	 *  glVertex2f(50.0 + base.x, 50.0 + base.y); //primer cuadrante
	 *  glVertex2f(50.0+base.x, -50.0+base.y); // cuarto cuadrante
	 *  glVertex2f(-50.0+base.x, -50.0+base.y); //tercer cuadrante
	 *  glVertex2f(-50.0+base.x, 50.0+base.y); //segundo cuadrante
	 */
=======
	glEnd();

	if (activateThruster == true) {
		Thruster();
	}

>>>>>>> feature/v0.0.4
}