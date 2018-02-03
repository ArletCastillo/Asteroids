#include "Vector3.hpp"
#include <cmath>
#include "Vector2.hpp"

Vector3 Vector3::Origin = Vector3();

Vector3::Vector3() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	lenght = 0.0f;
}

Vector3::Vector3(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
	lenght = 0.0f;
	Lenght();
}

Vector3::Vector3(float _value) {
	x = _value;
	y = _value;
	z = _value;
	lenght = 0.0f;
	Lenght();
}

Vector3::Vector3(const Vector2& v2) {
	x = v2.x;
	y = v2.y;
	z = 0.0f;
	lenght = 0.0f;
	Lenght();
}

float Vector3::Lenght() const {
	return sqrt(x * x + y * y + z * z);
}

float Vector3::SquaredLenght() const {
	return x * x + y * y + z * z;
}

float Vector3::Normalize() {
	Lenght();
	float inverScale = 1.0f / lenght;
	x *= inverScale;
	y *= inverScale;
	z *= inverScale;
	return lenght;
}

Vector3& Vector3::operator=(const Vector3& rightHandSide) {
	//prevents self assignment
	if (this == &rightHandSide)
		return *this;
	x = rightHandSide.x;
	y = rightHandSide.y;
	z = rightHandSide.z;
	return *this;
}

Vector3& Vector3::operator+=(const Vector3& rightHandSide) {
	x = x + rightHandSide.x;
	y = y + rightHandSide.y;
	z = z + rightHandSide.z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& rightHandSide) {
	x = x - rightHandSide.x;
	y = y - rightHandSide.y;
	z = z - rightHandSide.z;
	return *this;
}

Vector3& Vector3::operator*=(const Vector3& rightHandSide) {
	x = x * rightHandSide.x;
	y = y * rightHandSide.y;
	z = z * rightHandSide.z;
	return *this;
}

Vector3& Vector3::operator/=(const Vector3& rightHandSide) {
	if (rightHandSide.x == 0) throw "ERROR!";
	if (rightHandSide.y == 0) throw "ERROR!";
	if (rightHandSide.z == 0) throw "ERROR!";
	x = x / rightHandSide.x;
	y = y / rightHandSide.y;
	z = z / rightHandSide.z;
	return *this;
}

Vector3 Vector3::operator+(const Vector3& rightHandSide) const {
	return Vector3(x + rightHandSide.x, y + rightHandSide.y, z + rightHandSide.z);
}

Vector3 Vector3::operator-(const Vector3& rightHandSide) const {
	return Vector3(x - rightHandSide.x, y - rightHandSide.y, z - rightHandSide.z);
}

Vector3 Vector3::operator*(const Vector3& rightHandSide) const {
	return Vector3(x * rightHandSide.x, y * rightHandSide.y, z * rightHandSide.z);

}

Vector3 Vector3::operator/(const Vector3& rightHandSide) const {
	if (rightHandSide.x == 0) throw "ERROR!";
	if (rightHandSide.y == 0) throw "ERROR!";
	if (rightHandSide.z == 0) throw "ERROR!";
	return Vector3(x / rightHandSide.x, y/rightHandSide.y, z/rightHandSide.z);
}

bool Vector3::operator==(const Vector3& rightHandSide) const {
	return x == rightHandSide.x && y == rightHandSide.y && z == rightHandSide.z;
}

bool Vector3::operator!=(const Vector3& rightHandSide) const {
	return x != rightHandSide.x || y != rightHandSide.y || z != rightHandSide.z;
}

Vector3 operator*(float scaleUnit, const Vector3& rightHandSide) {
	return Vector3(scaleUnit * rightHandSide.x, scaleUnit*rightHandSide.y, scaleUnit*rightHandSide.z);
}

Vector3 operator*(const Vector3& leftHandSide, float scaleUnit) {
	return Vector3(scaleUnit * leftHandSide.x, scaleUnit * leftHandSide.y, scaleUnit * leftHandSide.z);
}