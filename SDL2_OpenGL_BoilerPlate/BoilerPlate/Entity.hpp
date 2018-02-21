#pragma once

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Vector2.hpp"

class Entity{
	protected:
		//members
		Vector2 base;
		float angle, mass;
		float maxHeight, maxWidth, halfHeight, halfWidth;

	public:
		//functions
		virtual void Render();
		virtual void Update();
		void Wrap(float&, float, float);
		void Move_forward();
		void Rotate_left();
		void Rotate_right();
};

#endif // !_ENTITY_H_