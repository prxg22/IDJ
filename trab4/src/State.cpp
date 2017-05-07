#include "State.hpp"

#include <algorithm>

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
	
	for(auto it = objects.rbegin(); it != objects.rend(); it++) {
		(*it)->update(dt);
	}
	
	if(input.keyPress(SPACE_KEY)){
		addObject(input.getMouseX(), input.getMouseY());
	}
	
	for(auto it = objects.begin(); it != objects.end(); ) {
		if((*it)->isDead()){
			it = objects.erase(it);
		} else {
			it++;
		}
	}
	
	std::sort(objects.begin(), objects.end(), [](const std::unique_ptr<GameObject>& a, const std::unique_ptr<GameObject>& b) {
		return a->z < b->z;
	});
}

void State::render() {
	bg.render(0, 0);
	tilemap->renderLayer(0);
	for (auto& obj : objects)
	{
		obj->render();
	}
	tilemap->renderLayer(1);
}

void State::addObject(float mouseX, float mouseY) {
	Vec2f v(0, 200);
	v = v.rotate(rand() % 360);
	v += Vec2f(mouseX, mouseY);
	Face* face = new Face(v.x, v.y);
	static int facez = 0;
	face->z = facez++;
	objects.emplace_back(face);
}