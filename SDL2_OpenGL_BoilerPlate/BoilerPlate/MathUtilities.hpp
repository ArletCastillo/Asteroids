#pragma once
class MathUtilities{
	public:
		int getNearestInt(float n);
		int getNearestEvenInt(float n);
		template <class T> T getMax(T n1, T n2);
		template <class T> T getMax(T n1, T n2, T n3);
		template <class T> T getMax(T n1, T n2, T n3, T n4);
		template <class T> T getMin(T n1, T n2);
		template <class T> T getMin(T n1, T n2, T n3);
		template <class T> T getMin(T n1, T n2, T n3, T n4);
		template <class T> T clamp(T n, T low, T high);
		float degToRad(float n);
		float radToDeg(float n);
		float degAngularDistance(float a1, float a2);
		float radAngularDistance(float a1, float a2);
		bool isPowerOfTwo(int x);
		template <class T> T interpolate(T s, T e, T target);
};

/*Get the maximun of two numbers and any type of variable.*/
template<class T>
inline T MathUtilities::getMax(T n1, T n2){
	T res = (n1 > n2) ? n1 : n2; //if n1 is greater than n2 then return n1 else return n2
	return (res);
}
/*Get the maximum of three numbers and any type of variable.*/
template<class T>
inline T MathUtilities::getMax(T n1, T n2, T n3){
	T maxx = n1;
	if (n2 > maxx)
		maxx = n2;
	if (n3 > maxx)
		maxx = n3;
	return (maxx);
}
/*Get the maximun of four numbers and any type of variable.*/
template<class T>
inline T MathUtilities::getMax(T n1, T n2, T n3, T n4){
	T maxx = n1;
	if (n2 > maxx)
		maxx = n2;
	if (n3 > maxx)
		maxx = n3;
	if (n4 > maxx)
		maxx = n4;
	return (maxx);
}
/*Get the minimum of two numbers and any type of variable.*/
template<class T>
inline T MathUtilities::getMin(T n1, T n2){
	T res = (n1 < n2) ? n1 : n2; //if n1 is less than n2 then return n1 else return n2
	return (res);
}
/*Get the minimum of three numbers and any type of variable.*/
template<class T>
inline T MathUtilities::getMin(T n1, T n2, T n3){
	T minn = n1;
	if (n2 < minn)
		minn = n2;
	if (n3 < minn)
		minn = n3;
	return (minn);
}
/*Get the minimum of four numbers and any type of variable.*/
template<class T>
inline T MathUtilities::getMin(T n1, T n2, T n3, T n4){
	T minn = n1;
	if (n2 < minn)
		minn = n2;
	if (n3 < minn)
		minn = n3;
	if (n4 < minn)
		minn = n4;
	return (minn);
}
/*Clamp a float (or an int) to be within a specified range*/
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
