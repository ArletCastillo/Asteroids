#pragma once
#ifndef _ASTEROID_H_
#define _ASTEROID_H_

#include <vector>
#include "Entity.hpp"

const int SMALL = 1;
const int MEDIUM = 2;
const int BIG = 4;

class  Asteroid: public Entity{
	private:
		//members
		std::vector<Vector2> asteroidContainer;
		int size;
		//private function
		void Change_size(int);

	public:
		//constructors
		Asteroid();
		//functions
		void Render();
		void Update();
		int Get_size(); 
};

#endif // !_ASTEROID_H_