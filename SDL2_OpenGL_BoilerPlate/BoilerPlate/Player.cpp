#include "Player.hpp"
#include <SDL2/SDL_opengl.h>
#include <cmath>
#include "MathUtilities.hpp"

const float MAXIMUM_SPEED = 350.0f;
const float ANGLE = 90.0f;
const float SPEED_X = 10.0f;
const float SPEED_Y = 10.0f;

void Player::ApplyImpulse(Vector2 impulse){
	if (m_mass > 0) {
		m_velocity.x += (impulse.x / m_mass) * cosf((m_angle + ANGLE) * (PI / 180));
		m_velocity.y += (impulse.y / m_mass) * sinf((m_angle + ANGLE) * (PI / 180));
	}
}

Player::Player() {
	m_base = Vector2(0, 0);
	m_angle = 0.0f;
	m_mass = 2.0f;
	m_radius = 30.0f;
	//ship's coordenates
	m_shipContainer.push_back(Vector2(0.0, 20.0));
	m_shipContainer.push_back(Vector2(12.0, -10.0));
	m_shipContainer.push_back(Vector2(6.0, -4.0));
	m_shipContainer.push_back(Vector2(-6.0, -4.0));
	m_shipContainer.push_back(Vector2(-12.0, -10.0));
	//thruster's coordenates
	m_thrusterContainer.push_back(Vector2(-6.0, -7.0));
	m_thrusterContainer.push_back(Vector2(6.0, -7.0));
	m_thrusterContainer.push_back(Vector2(0.0, -15.0));
}

void Player::Thruster() {
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < m_thrusterContainer.size(); i++)
		glVertex2f(m_thrusterContainer[i].x, m_thrusterContainer[i].y);
	glEnd();
}

void Player::MoveForward(){
	ApplyImpulse(Vector2(SPEED_X, SPEED_Y));
}

void Player::Render() {
	glLoadIdentity();
	glTranslatef(m_base.x, m_base.y, 0.0f);
	glRotatef(m_angle, 0.0f, 0.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
	for (int i=0;i<m_shipContainer.size();i++)
		glVertex2f(m_shipContainer[i].x, m_shipContainer[i].y);
	glEnd();

	if (activateThruster == true)
		Thruster();

	if(activateCircle == true)
		DrawCircle(m_base.x, m_base.y, m_radius);
}

void Player::Update(float time){
	//clamping speed as a scalar, since velocity is a vector
	float speed = fabs(sqrtf(pow(m_velocity.x, 2) + pow(m_velocity.y, 2)));

	m_velocity *= 0.99;

	//prevents ship form disappearing because of how fast is moving
	if (speed > MAXIMUM_SPEED) {
		m_velocity.x = (m_velocity.x / speed) * MAXIMUM_SPEED;
		m_velocity.y = (m_velocity.y / speed) * MAXIMUM_SPEED;
	}
	m_cSpeed = speed;
	Entity::Update(time);
}
