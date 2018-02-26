#pragma once

#ifndef _BULLET_H_
#define _BULLET_H_

#include "Entity.hpp"
#include <vector>
#include "Player.hpp"

class Bullet: public Entity{
	private:
		//member
		std::vector<Vector2> m_bulletContainer;
		int m_lifespan;
		bool m_isAlive;
		//private function
		void ApplyImpulse(Vector2);

	public:
		//constructor
		Bullet(Player*);
		//public memeber
		bool activateBullet;
		//function
		void Render() override;
		void Update(float) override;
};

#endif // !_BULLET_H_
