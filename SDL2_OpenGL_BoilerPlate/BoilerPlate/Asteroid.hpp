#pragma once
#ifndef _ASTEROID_H_
#define _ASTEROID_H_

#include <vector>
#include "Entity.hpp"

const float SMALL = 1.0f;
const float MEDIUM = 2.0f;
const float BIG = 4.0f;

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
		Asteroid(int);
		//functions
		void Render() override;
		void Update(float) override;
		int GetSize();
		void DrawLine(Vector2);
		void AssignPosition(Vector2);
		void ChangeSize();
};

#endif // !_ASTEROID_H_