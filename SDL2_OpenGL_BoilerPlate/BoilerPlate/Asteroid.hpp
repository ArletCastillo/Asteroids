#pragma once
#ifndef _ASTEROID_H_
#define _ASTEROID_H_

#include "Vector2.hpp"
#include <vector>

class  Asteroid{
	private:
		//members
		Vector2 base;
		std::vector<Vector2> asteroidContainer;
		float angle, mass;
		float maxHeight, maxWidth, halfHeight, halfWidth;
		int smll, medium, big;

	public:
		//public member
		bool activateThruster;
		//constructors
		Asteroid();
		//functions
		void Render();
		void Update();
		void Get_size(); //TO DO: tells the actual state of the asteroid.
		void Wrap(float&, float, float);
		void Move_forward();
		void Rotate_left();
		void Rotate_right();
};

#endif // !_ASTEROID_H_