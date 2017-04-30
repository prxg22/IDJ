#include <iostream> // entrada e saida do C++ (cin/cout/cerr)
#include <cstdio>   // entrada e saida do C (scanf/printf, stdin/stdout/stderr)
#include <ctime>    // funcoes de tempo do C

#include <SDL2/SDL.h> // SDL basica
#include <SDL2/SDL_image.h> // SDL image

using namespace std; // namespace da lib padrao do C++

// SDL context
SDL_Window* window;
SDL_Renderer* renderer;

// utils
void draw_rect(const SDL_Rect& rect, int r, int g, int b) {
	SDL_SetRenderDrawColor(renderer,r,g,b,0);
	SDL_RenderFillRect(renderer,&rect);
}
class Sprite {
	private:
		SDL_Texture* texture;
		int w, h;
	public:
		Sprite() : texture(nullptr) {
			
		}
		Sprite(const string& file_name) : texture(nullptr) {
			open(file_name);
		}
		~Sprite() {
			close();
		}
		void open(const string& file_name) {
			close();
			texture = IMG_LoadTexture(renderer,file_name.c_str());
			if (texture == nullptr) {
				fprintf(stderr, "%s\n", SDL_GetError());
				return;
			}
			SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
		}
		void close() {
			if (texture) {
				SDL_DestroyTexture(texture);
				texture = nullptr;
			}
		}
		void render(int x, int y) {
			SDL_Rect rect = {x, y, w, h};
			SDL_RenderCopy(renderer, texture, nullptr, &rect);
		}
};

// =====================================================================
// BEGIN game-specific code
// =====================================================================

// game world
bool quit = false;
Uint32 fixed_step = 30; // milisegundos
float dt = fixed_step/1000.0f; // segundos
int posx = 0, posy = 0;
Sprite* background = nullptr;

// init game world
void init_game() {
	background = new Sprite("background.jpg");
}

// close game world
void close_game() {
	delete background;
}

// update game world
void update_game() {
	SDL_Event event;
	while (!quit && SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_MOUSEBUTTONDOWN:
				printf("SDL_MOUSEBUTTONDOWN: x=%d y=%d\n",event.button.x,event.button.y);
				cout << endl;
				break;
			case SDL_MOUSEBUTTONUP:
				printf("SDL_MOUSEBUTTONUP: x=%d y=%d\n",event.button.x,event.button.y);
				cout << endl;
				break;
			case SDL_MOUSEMOTION:
				printf("SDL_MOUSEMOTION: x=%d y=%d\n",event.motion.x,event.motion.y);
				cout << endl;
				posx = event.motion.x, posy = event.motion.y;
				break;
			case SDL_KEYDOWN:
				printf("SDL_KEYDOWN: %d %c\n",event.key.keysym.sym,event.key.keysym.sym);
				cout << endl;
				break;
		}
	}
}

// render game world
void render_game() {
	background->render(0, 0);
	draw_rect({posx,posy,10,10},255,0,0);
}

// =====================================================================
// END game-specific code
// =====================================================================

// engine update
void update() {
	// inicializa o primeiro last_time
	static Uint32 last_time = 0;
	if (last_time == 0) {
		last_time = SDL_GetTicks();
		return;
	}
	
	// acumula o tempo que passou desde a ultima vez que update() foi chamada
	static Uint32 time_buffer = 0;
	Uint32 now = SDL_GetTicks();
	Uint32 delta_time = now-last_time;
	time_buffer += delta_time;
	
	// atualiza o proximo last_time como now
	last_time = now;
	
	// avanca todos os passos fixos que estiverem disponiveis no buffer de tempo
	while (time_buffer >= fixed_step) {
		time_buffer -= fixed_step;
		update_game();
	}
}

// engine render
void render() {
	SDL_SetRenderDrawColor(renderer,0,0,0,0);
	SDL_RenderClear(renderer);
	render_game();
	SDL_RenderPresent(renderer);
}

int main(int argc, char** argv) {
	// init libs
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_PNG);
	window = SDL_CreateWindow("i want to break free", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	// init game
	init_game();
	
	// main game loop
	while (!quit) {
		update();
		render();
	}
	
	// close game
	close_game();
	
	// close libs
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
	return 0;
}