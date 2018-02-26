#include "Bullet.hpp"
#include <SDL2/SDL_opengl.h>
#include "MathUtilities.hpp"
#include "Entity.hpp"

/*
position->x = playerShip.GetPosition().x + ((cosf(mathUtilities.degreesToRadians(bulletAngle)) +
playerShip.GetEntityRadius()) * (-sinf(mathUtilities.degreesToRadians(bulletAngle))));
position->y = playerShip.GetPosition().y + ((-sinf(mathUtilities.degreesToRadians(bulletAngle)) +
playerShip.GetEntityRadius()) * (cosf(mathUtilities.degreesToRadians(bulletAngle))));
*/

Bullet::Bullet(Player* ship){
	MathUtilities math;
	Vector2 shipPosition = ship->getOrigin();
	m_angle = ship->getAngle();
	float radians = math.degToRad(m_angle);
	//m_radius = 10.0f;
	//float shipRadius = ship->getRadius();
	m_mass = 1.0f;
	m_base.x = shipPosition.x + ship->getRadius() * -sinf(radians);
	m_base.y = shipPosition.y + ship->getRadius() * cosf(radians);
	m_velocity = 120.0f;
	m_lifespan = 50.0f;
	m_isAlive = true;
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
}

void Bullet::Update(float time){
	m_lifespan--;
	if (m_lifespan <= 0)
		m_isAlive = false;
	ApplyImpulse(Vector2(8.0f));
	Entity::Update(time);
}
