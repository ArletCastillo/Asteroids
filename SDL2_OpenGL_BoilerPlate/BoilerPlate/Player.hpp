#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Vector2.hpp"

class  Player{
	private:
		//member
		Vector2 base;
		float maxHeight, maxWidth, halfHeight, halfWidth;

	public:
		//public member
		bool activateThruster;
		//constructors
		 Player();
		 Player(float, float);
		 //functions
		 void moveBase(Vector2);
		 void Render();
		 void thruster();
		 void wrap(float&, float, float);
		 void moveForward();
		 void rotateLeft();
		 void rotateRight();
};
#endif // !_PLAYER_H_

