#include "Face.hpp"

#include "Game.hpp"

static int updateCounter = 0;

Face::Face(float x, float y) : hitpoints(30), sp("penguinface.png") {
	box.x = x - sp.getWidth()/2;
	box.y = y - sp.getHeight()/2;
	box.w = sp.getWidth();
	box.h = sp.getHeight();
}

void Face::damage(int damage){
	hitpoints -= damage;
}

void Face::update(float dt){
	auto& input = Game::getInstance().input;
	auto& camera = Game::getInstance().camera.pos;

	if(box.isInside(input.getMouseX() + camera.x, input.getMouseY() + camera.y) && input.mousePress(LEFT_MOUSE_BUTTON) && updateCounter < input.getUpdateCounter()) {
		damage(rand() % 10 + 10);
		updateCounter = input.getUpdateCounter();
	}
}

void Face::render(){
	auto pos = Vec2f(box.x, box.y) - Game::getInstance().camera.pos;

	sp.render(pos.x, pos.y);
}

bool Face::isDead() {
	return hitpoints <= 0;
}