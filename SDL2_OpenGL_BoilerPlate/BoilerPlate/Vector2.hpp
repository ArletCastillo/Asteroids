#pragma once
//prevents a header file from being included multiple times
#ifndef _VECTOR2_H_
#define _VECTOR2_H_

struct Vector2 {
	//members
	float x, y, lenght;
	static Vector2 Origin;
	
	//constructors
	Vector2();
	Vector2(float, float);
	Vector2(float);

	//public functions
	float Lenght() const;
	float SquaredLenght() const;
	float Normalize();
	float Distance(Vector2, Vector2);

	//operators
	Vector2& operator=(const Vector2& rightHandSide);
	Vector2& operator+=(const Vector2& rightHandSide);
	Vector2& operator-=(const Vector2& rightHandSide);
	Vector2& operator*=(const Vector2& rightHandSide);
	Vector2& operator/=(const Vector2& rightHandSide);
	Vector2 operator+(const Vector2& rightHandSide) const;
	Vector2 operator-(const Vector2& rightHandSide) const;
	Vector2 operator*(const Vector2& rightHandSide) const;
	Vector2 operator/(const Vector2& rightHandSide) const;
	bool operator==(const Vector2& rightHandSide) const;
	bool operator!=(const Vector2& rightHandSide) const;
	friend Vector2 operator*(float, const Vector2&);
	friend Vector2 operator*(const Vector2&, float);
};

#endif 