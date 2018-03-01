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
		bool eKey;
		bool gKey;
		bool fKey;
		bool zKey;
		bool spaceKey;

	public:
		//constructor
		InputManager();
		//functions
		bool GetW();
		bool GetA();
		bool GetS();
		bool GetD();
		bool GetQ();
		bool GetE();
		bool GetG();
		bool GetF();
		bool GetZ();
		bool GetSpace();

		void SetW(bool);
		void SetA(bool);
		void SetS(bool);
		void SetD(bool);
		void SetQ(bool);
		void SetE(bool);
		void SetG(bool);
		void SetF(bool);
		void SetZ(bool);
		void SetSpace(bool);
};

#endif // ! _INPUTMANAGER_H_
