#include "Game.hpp"

#include <cstdio>

#include <SDL2/SDL_image.h>

static Uint32 fixed_step = 30; // milliseconds

Game* Game::instance = nullptr;

Game::Game(const std::string& title, int width, int height) {
	if(instance != nullptr){
		exit(-1);
	}
	
	instance = this;
	
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_PNG);
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	state = new State();
}

Game::~Game() {
	delete state;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}


Game& Game::getInstance(){
	return *instance;
}

void Game::run() {
	while (!state->quitRequested()) {
		// inicializa o primeiro last_time
		static Uint32 last_time = 0;

		if (last_time == 0) {
			last_time = SDL_GetTicks();
			continue;
		}

		// acumula o tempo que passou desde a ultima vez que Game::run() foi chamada
		static Uint32 time_buffer = 0;
		Uint32 now = SDL_GetTicks();
		Uint32 delta_time = now-last_time;
		time_buffer += delta_time;

		// atualiza o proximo last_time como now
		last_time = now;

		// avanca todos os passos fixos que estiverem disponiveis no buffer de tempo
		while (time_buffer >= fixed_step) {
			time_buffer -= fixed_step;
			input.update();
			state->update(fixed_step/1000.0f);
		}
		// render
		state->render();
		SDL_RenderPresent(renderer);
	}
}

SDL_Renderer* Game::getRenderer() const {
	return renderer;
}

State& Game::getState() const {
	return *state;
}

std::string Game::getPath() const {
	return "../assets";
}