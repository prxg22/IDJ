#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "Rect.hpp"

class GameObject
{
public:
	Rect box;
	virtual ~GameObject();
	
	virtual void update(float dt) = 0;
	virtual void render() = 0;
	virtual bool isDead() = 0;
};

#endif