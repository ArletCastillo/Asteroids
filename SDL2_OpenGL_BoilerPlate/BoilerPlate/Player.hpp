#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <vector>
#include "Entity.hpp"

class  Player: public Entity{
	private:
		//members
		std::vector<Vector2> m_shipContainer;
		std::vector<Vector2> m_thrusterContainer;
		float m_cSpeed;
		//private function
		void Apply_impulse(Vector2);

	public:
		//public member
		bool activateThruster;
		//constructor
		Player();
		//functions
		void Move_forward();
		void Render();
		void Update(float);
		void Thruster();
};
#endif // !_PLAYER_H_

