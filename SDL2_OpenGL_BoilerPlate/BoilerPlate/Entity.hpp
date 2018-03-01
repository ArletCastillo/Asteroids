#pragma once

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Vector2.hpp"

const int SCREEN_WIDHT = 1136;
const int SCREEN_HEIGHT = 640;

class Entity{
	protected:
		//members
		Vector2 m_base;
		Vector2 m_velocity;
		float m_angle, m_mass, m_radius;
		float m_maxHeight, m_maxWidth, m_halfHeight, m_halfWidth, m_height, m_width;
		bool m_drawLine;
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
		Vector2 GetOrigin();
		float GetRadius();
		float GetAngle();
		bool GetDrawLine();
		void SetDrawLine(bool);
		void UpdateWrap(float, float);
};

#endif // !_ENTITY_H_