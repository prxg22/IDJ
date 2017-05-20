#include "InputManager.hpp"

#include <cstring>
#include <SDL2/SDL.h>

InputManager::InputManager() {
	memset(mouseState, false, sizeof mouseState);
	memset(mouseUpdate, 0, sizeof mouseUpdate);
	_quitRequested = 0;
	updateCounter = 1;
	mouseX = 0;
	mouseY = 0;
}

InputManager::~InputManager(){}


void InputManager::update() {
	updateCounter++;
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT:
				_quitRequested = updateCounter;
				break;
			case SDL_KEYDOWN:
				if(!event.key.repeat){
					keyUpdate[event.key.keysym.sym] = updateCounter;
				}
				keyState[event.key.keysym.sym] = true;
				break;
			case SDL_KEYUP:
				keyUpdate[event.key.keysym.sym] = -updateCounter;
				keyState[event.key.keysym.sym] = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				mouseUpdate[event.button.button] = updateCounter;
				mouseState[event.button.button] = true;
				break;
			case SDL_MOUSEBUTTONUP:
				mouseUpdate[event.button.button] = -updateCounter;
				mouseState[event.button.button] = false;
				break;
		}
	}
	SDL_GetMouseState(&mouseX, &mouseY);
}

bool InputManager::keyPress(int key) {
	if(!keyUpdate.count(key)) {
		return false;
	}
	return keyUpdate[key] == updateCounter;
}
bool InputManager::keyRelease(int key) {
	if(!keyUpdate.count(key)) {
		return false;
	}
	
	return keyUpdate[key] == -updateCounter;
}
bool InputManager::isKeyDown(int key) const {
	if(!keyState.count(key)) {
		return false;
	}
	
	return keyState.at(key);
}

bool InputManager::mousePress(int button) {
	return mouseUpdate[button] == updateCounter;
}
bool InputManager::mouseRelease(int button) {
	return mouseUpdate[button] == -updateCounter;
}
bool InputManager::isMouseDown(int button) const {
	return mouseState[button];
}

int InputManager::getMouseX() const {
	return mouseX;
}
int InputManager::getMouseY() const {
	return mouseY;
}

bool InputManager::quitRequested() {
	return _quitRequested == updateCounter;
}

int InputManager::getUpdateCounter() const {
	return updateCounter;
}