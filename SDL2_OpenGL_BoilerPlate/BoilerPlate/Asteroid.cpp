#include "Asteroid.hpp"
#include "Player.hpp"
#include <SDL2/SDL_opengl.h>
#include "MathUtilities.hpp"

Asteroid::Asteroid() {
	m_base = Vector2(-200.0f, -100.0f);
	m_angle = 0.0f;
	ChangeSize(BIG);
	m_mass = 1.0f;
	m_rotation = 100.0f;
	m_radius = 20.0f * m_size;
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

Asteroid::Asteroid(int size){
	m_base = Vector2(-200.0f, -100.0f);
	m_angle = 0.0f;
	if (size == SMALL)
		ChangeSize(SMALL);
	if (size == MEDIUM)
		ChangeSize(MEDIUM);
	m_mass = 1.0f;
	m_rotation = 100.0f;
	m_radius = 20.0f * m_size;
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

void Asteroid::AssignPosition(Vector2 position){
	m_base = position;
}

void Asteroid::ChangeSize() {
	for (int i = 0; i < m_asteroidContainer.size(); i++)
		m_asteroidContainer[i] = (1 / m_size) * m_asteroidContainer[i];
	m_radius = m_radius / m_size;
	if (m_size == SMALL)
		m_size = BIG;
	else if (m_size == MEDIUM)
		m_size = SMALL;
	else if (m_size == BIG)
		m_size = MEDIUM;
	for (int i = 0; i < m_asteroidContainer.size(); i++)
		m_asteroidContainer[i] = m_size * m_asteroidContainer[i];
	m_radius = m_radius * m_size;
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
