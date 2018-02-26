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
		std::vector<Vector2> m_asteroidContainer;
		int m_size;
		float m_rotation;
		//private function
		void ChangeSize(int);
		void ApplyImpulse(Vector2);

	public:
		//constructor
		Asteroid();
		//functions
		void Render() override;
		void Update(float) override;
		int GetSize();
		void DrawLine(Vector2);
};

#endif // !_ASTEROID_H_