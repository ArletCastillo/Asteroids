#include "Asteroid.hpp"
#include <SDL2/SDL_opengl.h>
#include "MathUtilities.hpp"

const float SPEED_X = 200.0f;
const float SPEED_Y = 0.0f;

Asteroid::Asteroid() {
	m_base = Vector2(0, 0);
	m_angle = 0.0f;
	Change_size(BIG);
	m_mass = 1.0f;
	m_rotation = 100.0f;
	//coordenates for the asteroid
	m_asteroidContainer.push_back(m_size*Vector2(0.0, 10.0));
	m_asteroidContainer.push_back(m_size*Vector2(9.0, 12.0));
	m_asteroidContainer.push_back(m_size*Vector2(17.0, 8.0));
	m_asteroidContainer.push_back(m_size*Vector2(14.0, 5.0));
	m_asteroidContainer.push_back(m_size*Vector2(17.0, 0.0));
	m_asteroidContainer.push_back(m_size*Vector2(11.0, -6.0));
	m_asteroidContainer.push_back(m_size*Vector2(0.0, -8.0));
	m_asteroidContainer.push_back(m_size*Vector2(-11.0, -6.0));
	m_asteroidContainer.push_back(m_size*Vector2(-9.0, 0.0));
	m_asteroidContainer.push_back(m_size*Vector2(-14.0, 6.0));
	m_asteroidContainer.push_back(m_size*Vector2(-9.0, 13.0));

	Apply_impulse(Vector2(SPEED_X, SPEED_Y));
}

int Asteroid::Get_size(){
	return m_size;
}

void Asteroid::Apply_impulse(Vector2 impulse){
	if (m_mass > 0) {
		m_velocity.x += (impulse.x / m_mass) * sinf(m_rotation * (PI / 180)) + m_size;
		m_velocity.y += (impulse.x / m_mass) * cosf(m_rotation * (PI / 180)) + m_size;
	}
}

void Asteroid::Render() {
	glLoadIdentity();
	glTranslatef(m_base.x, m_base.y, 0.0f);
	glRotatef(m_angle, 0.0f, 0.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
	for (int i=0;i<m_asteroidContainer.size();i++)
		glVertex2f(m_asteroidContainer[i].x, m_asteroidContainer[i].y);
	glEnd();
}

void Asteroid::Update(float time){
	m_angle += m_rotation * time;
	Entity::Update(time);
}

void Asteroid::Change_size(int _size) {
	m_size = _size;

}