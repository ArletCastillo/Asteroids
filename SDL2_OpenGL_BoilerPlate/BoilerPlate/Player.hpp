#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Vector2.hpp"
#include <vector>

class  Player{
	private:
		//members
		Vector2 base;
		std::vector<Vector2> shipContainer;
		std::vector<Vector2> thrusterContainer;
		float angle, mass;
		float maxHeight, maxWidth, halfHeight, halfWidth;

	public:
		//public member
		bool activateThruster;
		//constructors
		Player();
		//functions
		void Render();
		void Thruster();
		void Wrap(float&, float, float);
		void Move_forward();
		void Rotate_left();
		void Rotate_right();
};
#endif // !_PLAYER_H_

