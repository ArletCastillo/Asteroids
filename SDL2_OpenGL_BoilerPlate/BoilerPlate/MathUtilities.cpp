#include "MathUtilities.hpp"
#include <cmath>

/*Get the nearest int to a float.*/
int MathUtilities::getNearestInt(float n){
	int in = int(n + 0.5); //convert from float to integer (with rounding)
	return in;
}
/*Round a float to the nearest even integer value.*/
int MathUtilities::getNearestEvenInt(float n){
	int in = int(n + 0.5);
	if ((in % 2) != 0)
		in--;
	return in;
}
/*Convert an angle in degrees to radians*/
float MathUtilities::degToRad(float n){
	return n *= ((atan(1) * 4) / 180);
}
/*Convert an angle in radian to degrees*/
float MathUtilities::radToDeg(float n){
	return n *= (180 / (atan(1) * 4));
}
/*Calculate the angular distance from angle A to angle B (degree)*/
float MathUtilities::degAngularDistance(float a1, float a2){
	float res = abs(a1 - a2), rres;
	rres = radToDeg(res);
	return rres;

}
/*Calculate the angular distance from angle A to angle B (radians)*/
float MathUtilities::radAngularDistance(float a1, float a2) {
	float res = abs(a1 - a2), rres;
	rres = degToRad(res);
	return rres;
}
/*Determine if an int is a "power of two"*/
bool MathUtilities::isPowerOfTwo(int x)
{
	bool res = false;
	while (((x % 2) == 0) && x > 1) /* While x is even and > 1 */
		x /= 2;
	if (x == 1)
		res = true;
	else
		res = false;
	return res;
}
