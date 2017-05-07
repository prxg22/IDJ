#ifndef STATE_HPP
#define STATE_HPP

#include <vector>
#include <memory>

#include "Sprite.hpp"
#include "GameObject.hpp"
#include "Tilemap.hpp"

class State{
	private:
		Sprite bg;
		bool _quitRequested;
		std::vector<std::unique_ptr<GameObject>> objects;
		Tilemap* tilemap;
	public:
		State();
		~State();
		bool quitRequested() const;
		void update(float dt);
		void render();
	private:
		void addObject(float mouseX, float mouseY);
};

#endif