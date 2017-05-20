#include <cstdio>

#include "Camera.hpp"
#include "Game.hpp"
#include "Vec2.hpp"

#define CAMERA_SPEED 200

Camera::Camera(): focus(nullptr) {}

void Camera::follow(GameObject* newFocus) {
	focus = newFocus;
}

void Camera::unfollow() {
	focus = nullptr;
}

void Camera::update(float dt) {
	if (focus) {
		//TODO
	} else {
		speed = Vec2f::zero();
		auto& input = Game::getInstance().input;
		if (input.isKeyDown(SDLK_a)) {
			speed.x -= 1;
		}
		if (input.isKeyDown(SDLK_d)) {
			speed.x += 1;
		}
		if (input.isKeyDown(SDLK_w)) {
			speed.y -= 1;
		}
		if (input.isKeyDown(SDLK_s)) {
			speed.y += 1;
		}
		speed = speed.unitVec();
		speed *= CAMERA_SPEED;
		pos += speed * dt;
	}
}

