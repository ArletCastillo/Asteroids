#pragma once

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Vector2.hpp"

class Entity{
	protected:
		//members
		Vector2 m_base;
		Vector2 m_velocity;
		float m_angle, m_mass, m_radius;
		float m_maxHeight, m_maxWidth, m_halfHeight, m_halfWidth;

	public:
		//functions
		virtual void Render();
		virtual void Update(float);
		void Wrap(float&, float, float);
		void Move_forward();
		void Rotate_left();
		void Rotate_right();
};

#endif // !_ENTITY_H_