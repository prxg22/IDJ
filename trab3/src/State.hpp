#ifndef STATE_HPP
#define STATE_HPP

#include <list>
#include <memory>

#include "Sprite.hpp"
#include "GameObject.hpp"
#include "Tilemap.hpp"

class State{
	private:
		Sprite bg;
		bool _quitRequested;
		std::list<std::unique_ptr<GameObject>> objectList;
		Tilemap* tilemap;
	public:
		State();
		~State();
		bool quitRequested() const;
		void update(float dt);
		void render();
	private:
		void input();
		void addObject(float mouseX, float mouseY);
};

#endif