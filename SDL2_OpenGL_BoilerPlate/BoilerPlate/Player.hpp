#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <vector>
#include "Entity.hpp"

class  Player: public Entity{
	private:
		//members
		std::vector<Vector2> shipContainer;
		std::vector<Vector2> thrusterContainer;

	public:
		//public member
		bool activateThruster;
		//constructors
		Player();
		//functions
		void Render();
		void Thruster();
};
#endif // !_PLAYER_H_

