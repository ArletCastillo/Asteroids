#pragma once

#ifndef _VECTOR4_H_
#define _VECTOR4_H_

struct  Vector2;
struct Vector3;
struct Vector4 {
	//members
	float x, y, z, w, lenght;
	static Vector4 Origin;

	//constructors
	Vector4();
	Vector4(float, float, float, float);
	Vector4(float);
	Vector4(const Vector2&);
	Vector4(const Vector3&);

	//public functions
	float Lenght() const;
	float SquaredLenght() const;
	float Normalize();

	//operators
	Vector4& operator=(const Vector4&);
	Vector4& operator+=(const Vector4&);
	Vector4& operator-=(const Vector4&);
	Vector4& operator*=(const Vector4&);
	Vector4& operator/=(const Vector4&);
	Vector4 operator+(const Vector4&) const;
	Vector4 operator-(const Vector4&) const;
	Vector4 operator*(const Vector4&) const;
	Vector4 operator/(const Vector4&) const;
	bool operator==(const Vector4&) const;
	bool operator!=(const Vector4&) const;
	friend Vector4 operator*(float, const Vector4&);
	friend Vector4 operator*(const Vector4&, float);
};

#endif // ! _VECTOR4_H_
