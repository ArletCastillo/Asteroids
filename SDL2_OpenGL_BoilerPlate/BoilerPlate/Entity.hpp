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
		//protected function
		void DrawCircle(float x, float y, float radius);

	public:
		//public member
		bool activateCircle;
		//functions
		virtual void Render();
		virtual void Update(float);
		void Wrap(float&, float, float);
		void MoveForward();
		void RotateLeft();
		void RotateRight();
		Vector2 getOrigin();
		float getRadius();
		float getAngle();
};

#endif // !_ENTITY_H_