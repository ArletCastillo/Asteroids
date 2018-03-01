#include "InputManager.hpp"

InputManager::InputManager() {
	wKey = false;
	aKey = false;
	sKey = false;
	dKey = false;
	qKey = false;
	eKey = false;
	gKey = false;
	fKey = false;
	zKey = false;
	spaceKey = false;
}

bool InputManager::GetW() {
	return wKey;
}

bool InputManager::GetA() {
	return aKey;
}

bool InputManager::GetS() {
	return sKey;
}

bool InputManager::GetD() {
	return dKey;
}

bool InputManager::GetQ() {
	return qKey;
}

bool InputManager::GetE() {
	return eKey;
}

bool InputManager::GetG() {
	return gKey;
}

bool InputManager::GetF() {
	return fKey;
}

bool InputManager::GetZ() {
	return zKey;
}

bool InputManager::GetSpace() {
	return spaceKey;
}

void InputManager::SetW(bool value) {
	wKey = value;
}

void InputManager::SetA(bool value) {
	aKey = value;
}

void InputManager::SetS(bool value) {
	sKey = value;
}

void InputManager::SetD(bool value) {
	dKey = value;
}

void InputManager::SetQ(bool value) {
	qKey = value;
}

void InputManager::SetE(bool value) {
	eKey = value;
}

void InputManager::SetG(bool value) {
	gKey = value;
}

void InputManager::SetF(bool value) {
	fKey = value;
}

void InputManager::SetZ(bool value) {
	zKey = value;
}

void InputManager::SetSpace(bool value) {
	spaceKey = value;
}