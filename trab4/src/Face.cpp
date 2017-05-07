#include "Face.hpp"

#include "Game.hpp"

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
	if(box.isInside(input.getMouseX(), input.getMouseY()) && input.mousePress(LEFT_MOUSE_BUTTON)) {
		damage(rand() % 10 + 10);
	}
}

void Face::render(){
	sp.render(box.x, box.y);
}

bool Face::isDead() {
	return hitpoints <= 0;
}