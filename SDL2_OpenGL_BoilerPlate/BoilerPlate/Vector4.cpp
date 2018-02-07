#include "Vector4.hpp"
#include <cmath>
#include "Vector3.hpp"
#include "Vector2.hpp"

Vector4 Vector4::Origin = Vector4();

Vector4::Vector4() {
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
	lenght = 0.0f;
}

Vector4::Vector4(float _x, float _y, float _z, float _w) {
	x = _x;
	y = _y;
	z = _z;
	w = _w;
	lenght = 0.0f;
	Lenght();
}

Vector4::Vector4(float _value) {
	x = _value;
	y = _value;
	z = _value;
	w = _value;
	lenght = 0.0f;
	Lenght();
}

Vector4::Vector4(const Vector2& v2) {
	x = v2.x;
	y = v2.y;
	z = 0.0f;
	w = 0.0f;
	lenght = 0.0f;
	Lenght();
}

Vector4::Vector4(const Vector3& v3) {
	x = v3.x;
	y = v3.y;
	z = 0.0f;
	w = 0.0f;
	lenght = 0.0f;
	Lenght();
}

float Vector4::Lenght() const {
	return sqrt(x * x + y * y + z * z + w * w);
}

float Vector4::SquaredLenght() const {
	return x * x + y * y + z * z + w * w;
}

float Vector4::Normalize() {
	Lenght();
	float inverScale = 1.0f / lenght;
	x *= inverScale;
	y *= inverScale;
	z *= inverScale;
	w *= inverScale;
	return lenght;
}

Vector4& Vector4::operator=(const Vector4& rightHandSide) {
	//prevents self assignment
	if (this == &rightHandSide)
		return *this;
	x = rightHandSide.x;
	y = rightHandSide.y;
	z = rightHandSide.z;
	w = rightHandSide.w;
	return *this;
}

Vector4& Vector4::operator+=(const Vector4& rightHandSide) {
	x = x + rightHandSide.x;
	y = y + rightHandSide.y;
	z = z + rightHandSide.z;
	w = w + rightHandSide.w;
	return *this;
}

Vector4& Vector4::operator-=(const Vector4& rightHandSide) {
	x = x - rightHandSide.x;
	y = y - rightHandSide.y;
	z = z - rightHandSide.z;
	w = w - rightHandSide.w;
	return *this;
}

Vector4& Vector4::operator*=(const Vector4& rightHandSide) {
	x = x * rightHandSide.x;
	y = y * rightHandSide.y;
	z = z * rightHandSide.z;
	w = w * rightHandSide.w;
	return *this;
}

Vector4& Vector4::operator/=(const Vector4& rightHandSide) {
	if (rightHandSide.x == 0) throw "ERROR!";
	if (rightHandSide.y == 0) throw "ERROR!";
	if (rightHandSide.z == 0) throw "ERROR!";
	if (rightHandSide.w == 0) throw "ERROR!";
	x = x / rightHandSide.x;
	y = y / rightHandSide.y;
	z = z / rightHandSide.z;
	w = w / rightHandSide.w;
	return *this;
}

Vector4 Vector4::operator+(const Vector4& rightHandSide) const {
	return Vector4(x + rightHandSide.x, y + rightHandSide.y, z + rightHandSide.z, w + rightHandSide.w);
}

Vector4 Vector4::operator-(const Vector4& rightHandSide) const {
	return Vector4(x - rightHandSide.x, y - rightHandSide.y, z - rightHandSide.z, w - rightHandSide.w);
}

Vector4 Vector4::operator*(const Vector4& rightHandSide) const {
	return Vector4(x * rightHandSide.x, y * rightHandSide.y, z * rightHandSide.z, w * rightHandSide.w);

}

Vector4 Vector4::operator/(const Vector4& rightHandSide) const {
	if (rightHandSide.x == 0) throw "ERROR!";
	if (rightHandSide.y == 0) throw "ERROR!";
	if (rightHandSide.z == 0) throw "ERROR!";
	if (rightHandSide.w == 0) throw "ERROR!";
	return Vector4(x / rightHandSide.x, y / rightHandSide.y, z / rightHandSide.z, w / rightHandSide.w);
}

bool Vector4::operator==(const Vector4& rightHandSide) const {
	return x == rightHandSide.x && y == rightHandSide.y && z == rightHandSide.z && w == rightHandSide.w;
}

bool Vector4::operator!=(const Vector4& rightHandSide) const {
	return x != rightHandSide.x || y != rightHandSide.y || z != rightHandSide.z || w != rightHandSide.w;
}

Vector4 operator*(float scaleUnit, const Vector4& rightHandSide) {
	return Vector4(scaleUnit * rightHandSide.x, scaleUnit*rightHandSide.y, scaleUnit*rightHandSide.z, scaleUnit*rightHandSide.w);
}

Vector4 operator*(const Vector4& leftHandSide, float scaleUnit) {
	return Vector4(scaleUnit * leftHandSide.x, scaleUnit * leftHandSide.y, scaleUnit * leftHandSide.z, scaleUnit * leftHandSide.w);
}