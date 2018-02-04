#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Vector2.hpp"

class  Player{
	private:
		//member
		Vector2 base;

	public:
		//constructors
		 Player();
		 Player(float, float);
		 //functions
		 void moveBase(Vector2);
		 void Render();
};
#endif // !_PLAYER_H_

