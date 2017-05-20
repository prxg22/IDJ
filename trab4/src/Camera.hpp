#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "GameObject.hpp"
#include "Vec2.hpp"

class Camera {
private:
	GameObject* focus;

public:
	Vec2f pos;
	Vec2f speed;

	Camera();

	void follow(GameObject* newFocus);
	void unfollow();
	void update(float dt);
};
#endif