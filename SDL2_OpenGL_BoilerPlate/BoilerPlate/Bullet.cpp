#include "Bullet.hpp"
#include <SDL_opengl.h>
#include "MathUtilities.hpp"
#include "Entity.hpp"

Bullet::Bullet(Player* ship){
	MathUtilities math;
	Vector2 shipPosition = ship->GetOrigin();
	m_angle = ship->GetAngle();
	float radians = math.degToRad(m_angle);
	m_radius = 3.0f;
	m_mass = 1.0f;
	m_base.x = shipPosition.x + ship->GetRadius() * -sinf(radians);
	m_base.y = shipPosition.y + ship->GetRadius() * cosf(radians);
	m_velocity = 0.0f;
	m_lifespan = 70.0f;
	m_isAlive = true;
	m_width = SCREEN_WIDHT / 2;
	m_height = SCREEN_HEIGHT / 2;
	//coordenates for the bullet
	m_bulletContainer.push_back(0.10f*Vector2(0.0f, 10.0f));
	m_bulletContainer.push_back(0.10f*Vector2(9.0f, 12.0f));
	m_bulletContainer.push_back(0.10f*Vector2(17.0f, 8.0f));
	m_bulletContainer.push_back(0.10f*Vector2(14.0f, 5.0f));
	m_bulletContainer.push_back(0.10f*Vector2(17.0f, 0.0f));
	m_bulletContainer.push_back(0.10f*Vector2(11.0f, -6.0f));
	m_bulletContainer.push_back(0.10f*Vector2(0.0f, -8.0f));
	m_bulletContainer.push_back(0.10f*Vector2(-11.0f, -6.0f));
	m_bulletContainer.push_back(0.10f*Vector2(-9.0f, 0.0f));
	m_bulletContainer.push_back(0.10f*Vector2(-14.0f, 6.0f));
	m_bulletContainer.push_back(0.10f*Vector2(-9.0f, 13.0f));
}

void Bullet::ApplyImpulse(Vector2 impulse) {
	MathUtilities math;
	float angle = math.degToRad(m_angle);
	m_velocity.x -= (impulse.x) * sinf(angle);
	m_velocity.y += (impulse.y) * cosf(angle);
}

void Bullet::Render(){
	glLoadIdentity();
	glTranslatef(m_base.x, m_base.y, 0.0f);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i<m_bulletContainer.size(); i++)
		glVertex2f(m_bulletContainer[i].x, m_bulletContainer[i].y);
	glEnd();

	if (activateCircle == true)
		DrawCircle(m_base.x, m_base.y, m_radius);
}

void Bullet::Update(float time){
	m_lifespan--;
	if (m_lifespan <= 0)
		m_isAlive = false;
	ApplyImpulse(Vector2(8.0f));
	Entity::Update(time);
}
