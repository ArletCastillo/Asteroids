#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Vector2.hpp"

class  Player{
	private:
		//members
		Vector2 base;
<<<<<<< HEAD
=======
		float angle, mass;
>>>>>>> feature/v0.0.4
		float maxHeight, maxWidth, halfHeight, halfWidth;

	public:
		//public member
		bool activateThruster;
		//constructors
<<<<<<< HEAD
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
=======
		Player();
		Player(float, float);
		//functions
		void Render();
		void Thruster();
		void Wrap(float&, float, float);
		void Move_forward();
		void Rotate_left();
		void Rotate_right();
>>>>>>> feature/v0.0.4
};
#endif // !_PLAYER_H_

