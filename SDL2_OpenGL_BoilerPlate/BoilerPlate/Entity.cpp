#include "Entity.hpp"
#include <cmath>
#include "MathUtilities.hpp"
#include <SDL_opengl.h>

void Entity::Render(){
}

void Entity::Update(float time){
	m_base.x += m_velocity.x * static_cast<float>(time);
	m_base.y += m_velocity.y * static_cast<float>(time);

	m_halfWidth = SCREEN_WIDHT / 2.0f;
	m_halfHeight = SCREEN_HEIGHT / 2.0f;

	Wrap(m_base.x, -m_width, m_width);
	Wrap(m_base.y, -m_height, m_height);
}

void Entity::Wrap(float& vertex, float min, float max) {
	if (vertex < min) 
		vertex = max - (min - vertex);
	if (vertex > max) 
		vertex = min + (vertex - max);
}

void Entity::MoveForward(){
	m_halfWidth = SCREEN_WIDHT / 2.0f;
	m_halfHeight = SCREEN_HEIGHT / 2.0f;

	MathUtilities realAngle;
	m_base += Vector2(8 * sin(realAngle.degToRad(m_angle)*-1), 8 * cos(realAngle.degToRad(m_angle)));
}

void Entity::RotateLeft() {
	m_angle += 5.0f;
}

void Entity::RotateRight() {
	m_angle -= 5.0f;
}

Vector2 Entity::GetOrigin(){
	return m_base;
}

float Entity::GetRadius(){
	return m_radius;
}

float Entity::GetAngle(){
	return m_angle;
}

bool Entity::GetDrawLine(){
	return m_drawLine;
}

void Entity::SetDrawLine(bool boolValue){
	m_drawLine = boolValue;
}

void Entity::UpdateWrap(float width, float height){
	m_width = width/2;
	m_height = height/2;
}

void Entity::DrawCircle(float x, float y, float radius){
	float lineAmount = 100.0f;
	float twicePi = 2.0f * PI;
	glLoadIdentity();
	glTranslatef(x, y, 0.0f);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= lineAmount; i++)
		glVertex2f((radius*cosf(i*twicePi / lineAmount)), (radius*sinf(i*twicePi / lineAmount)));
	glEnd();
}
