#include "MathUtilities.hpp"
#include <cmath>

int MathUtilities::floatToInt(float n){
	int in = int(n + 0.5); //converts from float to integer (with rounding),
	return in;
}

int MathUtilities::floatToEvenInt(float n){
	int in = int(n + 0.5);
	if ((in % 2) != 0)
		in--;
	return in;
}

float MathUtilities::degToRad(float n){
	return n *= ((atan(1) * 4) / 180);
}

float MathUtilities::radToDeg(float n){
	return n *= (180 / (atan(1) * 4));
}

float MathUtilities::degAngularDistance(float a, float b){
	float res = abs(a - b), rres;
	rres = radToDeg(res);
	return rres;

}

float MathUtilities::radAngularDistance(float a, float b) {
	float res = abs(a - b), rres;
	rres = degToRad(res);
	return rres;
}

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
