#include "Entity.hpp"
#include <cmath>
#include "MathUtilities.hpp"

void Entity::Wrap(float& vertex, float min, float max) {
	if (vertex < min) {
		vertex = max - (min - vertex);
	}
	if (vertex > max) {
		vertex = min - (max - vertex);
	}
}

void Entity::Move_forward() {
	maxWidth = 1136 / 2.0f;
	halfWidth = -1136 / 2.0f;

	maxHeight = 640 / 2.0f;
	halfHeight = -640 / 2.0f;

	MathUtilities realAngle;
	base += Vector2(8 * sin(realAngle.degToRad(angle)*-1), 8 * cos(realAngle.degToRad(angle)));

	Wrap(base.x, halfWidth, maxWidth);
	Wrap(base.y, halfHeight, maxHeight);
}

void Entity::Rotate_left() {
	angle += 5;
}

void Entity::Rotate_right() {
	angle -= 5;
}