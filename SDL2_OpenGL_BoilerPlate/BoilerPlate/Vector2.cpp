#include "Vector2.hpp"
#include <cmath>

Vector2 Vector2::Origin = Vector2();

Vector2::Vector2() {
	x = 0.0f;
	y = 0.0f;
	lenght = 0.0f;
}

Vector2::Vector2(float _x, float _y) {
	x = _x;
	y = _y;
	lenght = 0.0f;
	Lenght();
}

Vector2::Vector2(float _value) {
	x = _value;
	y = _value;
	lenght = 0.0f;
	Lenght();
}

float Vector2::Lenght() const {
	return sqrt(x * x + y * y);
}

float Vector2::SquaredLenght() const {
	return x * x + y * y;
}

float Vector2::Normalize() {
	float inverseScale = 1.0f / lenght;
	x *= inverseScale;
	y *= inverseScale;
	lenght = Lenght();
	return lenght;
}

float Vector2::Distance(Vector2 player, Vector2 asteroid){
	return sqrt(pow(asteroid.x - player.x, 2) + pow(asteroid.y - player.y, 2));
}

Vector2& Vector2::operator=(const Vector2& rightHandSide) {
	//prevents self assignment
	if (this == &rightHandSide)
		return *this;
	x = rightHandSide.x;
	y = rightHandSide.y;
	return *this;
}

Vector2& Vector2::operator+=(const Vector2& rightHandSide) {
	x = x + rightHandSide.x;
	y = y + rightHandSide.y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& rightHandSide) {
	x = x - rightHandSide.x;
	y = y - rightHandSide.y;
	return *this;
}

Vector2& Vector2::operator*=(const Vector2& rightHandSide) {
	x = x * rightHandSide.x;
	y = y * rightHandSide.y;
	return *this;
}

Vector2& Vector2::operator/=(const Vector2& rightHandSide) {
	if (rightHandSide.x == 0) throw "ERROR!";
	if (rightHandSide.y == 0) throw "ERROR!";
	x = x / rightHandSide.x;
	y = y / rightHandSide.y;
	return *this;
}

Vector2 Vector2::operator+(const Vector2& rightHandSide) const {
	return Vector2(x + rightHandSide.x, y + rightHandSide.y);
}

Vector2 Vector2::operator-(const Vector2& rightHandSide) const {
	return Vector2(x - rightHandSide.x, y - rightHandSide.y);
}

Vector2 Vector2::operator*(const Vector2& rightHandSide) const {
	return Vector2(x*rightHandSide.x, y*rightHandSide.y);
}

Vector2 Vector2::operator/(const Vector2& rightHandSide) const {
	if (rightHandSide.x == 0) throw "ERROR!";
	if (rightHandSide.y == 0) throw "ERROR!";
}

bool Vector2::operator==(const Vector2& rightHandSide) const {
	return x == rightHandSide.x && y == rightHandSide.y;
}

bool Vector2::operator!=(const Vector2& rightHandSide) const {
	return x != rightHandSide.x || y != rightHandSide.y;
}

Vector2 operator*(float scaleUnit, const Vector2& rightHandSide) {
	return Vector2(scaleUnit*rightHandSide.x, scaleUnit*rightHandSide.y);
}

Vector2 operator*(const Vector2& leftHandSide, float scaleUnit) {
	return Vector2(scaleUnit*leftHandSide.x, scaleUnit*leftHandSide.y);
}