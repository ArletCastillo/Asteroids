#pragma once

#ifndef _VECTOR3_H_
#define _VECTOR3_H_

struct  Vector2;
struct Vector3{
	//members
	float x, y, z, lenght;
	static Vector3 Origin;

	//constructors
	Vector3();
	Vector3(float, float, float);
	Vector3(float);
	Vector3(const Vector2&);

	//public functions
	float Lenght() const;
	float SquaredLenght() const;
	float Normalize();

	//operators
	Vector3& operator=(const Vector3&);
	Vector3& operator+=(const Vector3&);
	Vector3& operator-=(const Vector3&);
	Vector3& operator*=(const Vector3&);
	Vector3& operator/=(const Vector3&);
	Vector3 operator+(const Vector3&) const;
	Vector3 operator-(const Vector3&) const;
	Vector3 operator*(const Vector3&) const;
	Vector3 operator/(const Vector3&) const;
	bool operator==(const Vector3&) const;
	bool operator!=(const Vector3&) const;
	friend Vector3 operator*(float, const Vector3&);
	friend Vector3 operator*(const Vector3&, float);
};

#endif // ! _VECTOR3_H_
