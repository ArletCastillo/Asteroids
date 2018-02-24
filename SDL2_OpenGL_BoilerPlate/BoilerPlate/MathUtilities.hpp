#pragma once

static double PI = 3.14159;

class MathUtilities{
	public:
		//functions
		int floatToInt(float); 
		int floatToEvenInt(float); //Rounds a float to the nearest even integer value.
		template <class T> T max(T, T); 
		template <class T> T max(T, T, T); 
		template <class T> T max(T, T, T, T); 
		template <class T> T min(T, T); 
		template <class T> T min(T, T, T); 
		template <class T> T min(T, T, T, T); 
		template <class T> T clamp(T, T, T);
		float degToRad(float); //converts an angle in degrees to radians.
		float radToDeg(float); //Converts an angle in radians to degrees.
		float degAngularDistance(float, float); //Angular distance in degrees.
		float radAngularDistance(float, float); //Angular distance in radians.
		bool isPowerOfTwo(int); //Determines if an int is a "power of two".
		template <class T> T interpolate(T, T, T);
};

template<class T>
inline T MathUtilities::max(T n1, T n2){
	T res = (n1 > n2) ? n1 : n2; //if n1 is greater than n2 then return n1 else return n2
	return (res);
}

template<class T>
inline T MathUtilities::max(T n1, T n2, T n3){
	T maxx = n1;
	if (n2 > maxx)
		maxx = n2;
	if (n3 > maxx)
		maxx = n3;
	return (maxx);
}

template<class T>
inline T MathUtilities::max(T n1, T n2, T n3, T n4){
	T maxx = n1;
	if (n2 > maxx)
		maxx = n2;
	if (n3 > maxx)
		maxx = n3;
	if (n4 > maxx)
		maxx = n4;
	return (maxx);
}

template<class T>
inline T MathUtilities::min(T n1, T n2){
	T res = (n1 < n2) ? n1 : n2; //if n1 is less than n2 then return n1 else return n2
	return (res);
}

template<class T>
inline T MathUtilities::min(T n1, T n2, T n3){
	T minn = n1;
	if (n2 < minn)
		minn = n2;
	if (n3 < minn)
		minn = n3;
	return (minn);
}

template<class T>
inline T MathUtilities::min(T n1, T n2, T n3, T n4){
	T minn = n1;
	if (n2 < minn)
		minn = n2;
	if (n3 < minn)
		minn = n3;
	if (n4 < minn)
		minn = n4;
	return (minn);
}

template<class T>
inline T MathUtilities::clamp(T n, T low, T high){
	if (n < low)
		n = low;
	else if (n > high)
		n = high;
	return (n);
}

template<class T>
inline T MathUtilities::interpolate(T s, T e, T target){
	return target * (e - s) + s;
}