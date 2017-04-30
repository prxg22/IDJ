#include "Game.hpp"

#include <cstdio>
#include <iostream>

#include <SDL2/SDL_image.h>
#include "Rect.hpp"
#include "Vec2.hpp"

static Uint32 fixed_step = 30; // milliseconds

Game* Game::instance = nullptr;

Game::Game(const std::string& title, int width, int height) {
	Vec2f a(50.16, 10),b,c,d;
	b = {x: 10.20, y:89.6};
	
	printf("qualquer coisa\n");
	c = a + b;
	std::cout << "Resultado add x: " << c.x << " y: " << c.y << "\n";
	std::cout << "Resultado norm(a): " << a.norm() << "\n";
	std::cout << "Resultado norm2(a): " << b.norm2() << "\n";
	
	if(instance != nullptr){
		exit(-1);
	}
	
	instance = this;
	
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_PNG);
	window = SDL_CreateWindow("i want to break free", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
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
		// input 
		SDL_Event event;
		while (!state->quitRequested() && SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				state->requestQuit();
			}
		}

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
			state->update(fixed_step/1000.0f);
		}
		// render
		state->render();
		SDL_RenderPresent(renderer);
	}
}

SDL_Renderer* Game::getRenderer(){
	return renderer;
}

State& Game::getState(){
	return *state;
}
