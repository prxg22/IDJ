#include "Face.hpp"

Face::Face(float x, float y) : hitpoints(30), sp("penguinface.png") {
	box.x = x - sp.getWidth()/2;
	box.y = y - sp.getHeight()/2;
	box.w = sp.getWidth();
	box.h = sp.getHeight();
}

void Face::damage(int damage){
	hitpoints -= damage;
}

void Face::update(float dt){}

void Face::render(){
	sp.render(box.x, box.y);
}

bool Face::isDead() {
	return hitpoints <= 0;
}