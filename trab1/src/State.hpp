#ifndef STATE_HPP
#define STATE_HPP

#include "Sprite.hpp"

class State{
	private:
		Sprite bg;
		bool _quitRequested;
		
	public:
		State();
		bool quitRequested();
		void requestQuit();
		void update(float dt);
		void render();
};

#endif