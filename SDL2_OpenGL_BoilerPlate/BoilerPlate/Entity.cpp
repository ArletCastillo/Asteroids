#include "Entity.hpp"
#include <cmath>
#include "MathUtilities.hpp"
#include <SDL2/SDL_opengl.h>

const int SCREEN_WIDHT = 1136;
const int SCREEN_HEIGHT = 640;

void Entity::Render(){
}

void Entity::Update(float time){
	m_base.x += m_velocity.x * static_cast<float>(time);
	m_base.y += m_velocity.y * static_cast<float>(time);

	m_halfWidth = SCREEN_WIDHT / 2.0f;
	m_halfHeight = SCREEN_HEIGHT / 2.0f;

	Wrap(m_base.x, -m_halfWidth, m_halfWidth);
	Wrap(m_base.y, -m_halfHeight, m_halfHeight);
}

void Entity::Wrap(float& vertex, float min, float max) {
	if (vertex < min) 
		vertex = max - (min - vertex);
	if (vertex > max) 
		vertex = min + (vertex - max);
}

void Entity::Move_forward(){
	m_halfWidth = SCREEN_WIDHT / 2.0f;
	m_halfHeight = SCREEN_HEIGHT / 2.0f;

	MathUtilities realAngle;
	m_base += Vector2(8 * sin(realAngle.degToRad(m_angle)*-1), 8 * cos(realAngle.degToRad(m_angle)));
}

void Entity::Rotate_left() {
	m_angle += 5;
}

void Entity::Rotate_right() {
	m_angle -= 5;
}

void Entity::Draw_circle(float x, float y, float radius){
	float lineAmount = 100.0f;
	float twicePi = 2.0f * PI;
	glLoadIdentity();
	glTranslatef(x, y, 0.0f);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= lineAmount; i++)
		glVertex2f((radius*cosf(i*twicePi / lineAmount)), (radius*sinf(i*twicePi / lineAmount)));
	glEnd();
}
