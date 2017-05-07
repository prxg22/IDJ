#ifndef GAME_HPP
#define GAME_HPP

#include <string>

#include <SDL2/SDL.h>

#include "State.hpp"
#include "Resources.hpp"

class Game{
	private:
		static Game* instance;
		SDL_Window* window;
		SDL_Renderer* renderer;
		State* state;
	public:
		Resources resources;
		Game(const std::string& title, int width, int height);
		~Game();
		static Game& getInstance();
		void run();
		SDL_Renderer* getRenderer() const;
		State& getState() const;
		std::string getPath() const;
};

#endif