#include "Asteroid.hpp"
#include <SDL2/SDL_opengl.h>

Asteroid::Asteroid() {
	base = Vector2(0, 0);
	angle = 0.0f;
	Change_size(BIG);
	//coordenates for the asteroid
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

int Asteroid::Get_size(){
	return size;
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