#include "State.hpp"

State::State() : _quitRequested(false), bg("background.jpg") {}

bool State::quitRequested() {
	return _quitRequested;
}

void State::requestQuit() {
	_quitRequested = true;
}

void State::update(float dt){
	
}

void State::render() {
	bg.render(0, 0);
}
