#include "State.hpp"

#include "Face.hpp"
#include "Vec2.hpp"
#include "Game.hpp"

State::State() : _quitRequested(false), bg("ocean.jpg"), tilemap(Game::getInstance().resources.getTilemap("tileMap.txt")) {}
State::~State() {}

bool State::quitRequested() const {
	return _quitRequested;
}

void State::update(float dt){
	auto& input = Game::getInstance().input;
	
	_quitRequested = input.quitRequested();
	
	for(auto it = objectList.rbegin(); it != objectList.rend(); it++) {
		(*it)->update(dt);
	}
	
	if(input.keyPress(SPACE_KEY)){
		addObject(input.getMouseX(), input.getMouseY());
	}
	
	for(auto it = objectList.begin(); it != objectList.end(); ) {
		if((*it)->isDead()){
			it = objectList.erase(it);
		} else {
			it++;
		}
	}
}

void State::render() {
	bg.render(0, 0);
	tilemap->renderLayer(0);
	for (auto& obj : objectList)
	{
		obj->render();
	}
	tilemap->renderLayer(1);
}

void State::addObject(float mouseX, float mouseY) {
	Vec2f v(0, 200);
	v = v.rotate(rand() % 360);
	v += Vec2f(mouseX, mouseY);
	objectList.emplace_back(new Face(v.x, v.y));
}