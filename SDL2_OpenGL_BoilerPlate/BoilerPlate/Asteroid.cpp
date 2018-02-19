#include "Asteroid.hpp"
#include <SDL2/SDL_opengl.h>
#include <cmath>
#include "MathUtilities.hpp"


Asteroid::Asteroid() {
	base = Vector2(0, 0);
	angle = 0.0f;
	Change_size(BIG);
	asteroidContainer.push_back(size*Vector2(0.0, 10.0));
	asteroidContainer.push_back(size*Vector2(9.0, 12.0));
	asteroidContainer.push_back(size*Vector2(17.0, 8.0));
	asteroidContainer.push_back(size*Vector2(14.0, 5.0));
	asteroidContainer.push_back(size*Vector2(17.0, 0.0));
	asteroidContainer.push_back(size*Vector2(11.0, -6.0));
	asteroidContainer.push_back(size*Vector2(0.0, -8.0));
	asteroidContainer.push_back(size*Vector2(-11.0, -6.0));
	asteroidContainer.push_back(size*Vector2(-9.0, 0.0));
	asteroidContainer.push_back(size*Vector2(-14.0, 6.0));
	asteroidContainer.push_back(size*Vector2(-9.0, 13.0));
}

void Asteroid::Wrap(float& vertex, float min, float max) {
	if (vertex < min) {
		vertex = max - (min - vertex);
	}
	if (vertex > max) {
		vertex = min - (max - vertex);
	}
}

void Asteroid::Move_forward() {
	maxWidth = 1136 / 2.0f;
	halfWidth = -1136 / 2.0f;

	maxHeight = 640 / 2.0f;
	halfHeight = -640 / 2.0f;

	MathUtilities realAngle;
	base += Vector2(8 * sin(realAngle.degToRad(angle)*-1), 8 * cos(realAngle.degToRad(angle)));

	Wrap(base.x, halfWidth, maxWidth);
	Wrap(base.y, halfHeight, maxHeight);
}

void Asteroid::Rotate_left() {
	angle += 5;
}

void Asteroid::Rotate_right() {
	angle -= 5;
}

void Asteroid::Render() {
	glLoadIdentity();
	glTranslatef(base.x, base.y, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
	for (int i=0;i<asteroidContainer.size();i++)
		glVertex2f(asteroidContainer[i].x, asteroidContainer[i].y);
	glEnd();
}

void Asteroid::Change_size(int _size) {
	size = _size;

}