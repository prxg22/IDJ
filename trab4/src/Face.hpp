#ifndef FACE_HPP
#define FACE_HPP

#include "GameObject.hpp"
#include "Sprite.hpp"

class Face : public GameObject
{
private:
	int hitpoints;
	Sprite sp;

public:
	Face(float x, float y);
	
	void damage(int damage);
	void update(float dt);
	void render();
	bool isDead();
};

#endif
