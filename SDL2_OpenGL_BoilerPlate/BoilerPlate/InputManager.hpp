#pragma once

#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

#include "Entity.hpp"
#include "Vector2.hpp"
#include <vector>

class  InputManager{
	private:
		//memebers
		bool wKey;
		bool aKey;
		bool sKey;
		bool dKey;
		bool qKey;
		bool gKey;
		bool fKey;
		bool zKey;

	public:
		//constructor
		InputManager();
		//functions
		bool GetW();
		bool GetA();
		bool GetS();
		bool GetD();
		bool GetG();
		bool GetF();
		bool GetZ();

		void SetW(bool);
		void SetA(bool);
		void SetS(bool);
		void SetD(bool);
		void SetG(bool);
		void SetF(bool);
		void SetZ(bool);
};

#endif // ! _INPUTMANAGER_H_
