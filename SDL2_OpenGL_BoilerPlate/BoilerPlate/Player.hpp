#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <vector>
#include "Entity.hpp"

const float MAXIMUM_SPEED = 350.0f;
const float ANGLE = 90.0f;

class  Player: public Entity{
	private:
		//members
		std::vector<Vector2> m_shipContainer;
		std::vector<Vector2> m_thrusterContainer;
		float m_cSpeed;
		//private function
		void ApplyImpulse(Vector2);

	public:
		//public member
		bool activateThruster;
		//constructor
		Player();
		//functions
		void MoveForward();
		void Render() override;
		void Update(float) override;
		void Thruster();
		std::vector<Vector2> ObtainLives();
};
#endif // !_PLAYER_H_

