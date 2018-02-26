#include "Asteroid.hpp"
#include "Player.hpp"
#include <SDL2/SDL_opengl.h>
#include "MathUtilities.hpp"

Asteroid::Asteroid(float x, float y) {
	m_base = Vector2(x, y);
	m_angle = 0.0f;
	ChangeSize(BIG);
	m_mass = 1.0f;
	m_rotation = 100.0f;
	m_radius = 60.0f;
	//coordenates for the asteroid
	m_asteroidContainer.push_back(m_size*Vector2(0.0f, 10.0f));
	m_asteroidContainer.push_back(m_size*Vector2(9.0f, 12.0f));
	m_asteroidContainer.push_back(m_size*Vector2(17.0f, 8.0f));
	m_asteroidContainer.push_back(m_size*Vector2(14.0f, 5.0f));
	m_asteroidContainer.push_back(m_size*Vector2(17.0f, 0.0f));
	m_asteroidContainer.push_back(m_size*Vector2(11.0f, -6.0f));
	m_asteroidContainer.push_back(m_size*Vector2(0.0f, -8.0f));
	m_asteroidContainer.push_back(m_size*Vector2(-11.0f, -6.0f));
	m_asteroidContainer.push_back(m_size*Vector2(-9.0f, 0.0f));
	m_asteroidContainer.push_back(m_size*Vector2(-14.0f, 6.0f));
	m_asteroidContainer.push_back(m_size*Vector2(-9.0f, 13.0f));

	ApplyImpulse(Vector2(100.0f));
}

int Asteroid::GetSize(){
	return m_size;
}

void Asteroid::ApplyImpulse(Vector2 impulse){
	if (m_mass > 0) {
		m_velocity.x += (impulse.x / m_mass) * sinf(m_rotation * (PI / 180)) + m_size;
		m_velocity.y += (impulse.x / m_mass) * cosf(m_rotation * (PI / 180)) + m_size;
	}
}

void Asteroid::DrawLine(Vector2 player){
	glLoadIdentity();
	glBegin(GL_LINE_LOOP);
	glVertex2f(player.x, player.y);
	glVertex2f(m_base.x, m_base.y);
	glEnd();
}

void Asteroid::Render() {
	glLoadIdentity();
	glTranslatef(m_base.x, m_base.y, 0.0f);
	glRotatef(m_angle, 0.0f, 0.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
	for (int i=0;i<m_asteroidContainer.size();i++)
		glVertex2f(m_asteroidContainer[i].x, m_asteroidContainer[i].y);
	glEnd();

	if(activateCircle == true)
		DrawCircle(m_base.x, m_base.y, m_radius);
}

void Asteroid::Update(float time){
	m_angle += m_rotation * time;
	Entity::Update(time);
}

void Asteroid::ChangeSize(int _size) {
	m_size = _size;

}
