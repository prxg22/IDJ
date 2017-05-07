#include "Game.hpp"

int main(int argc, char** argv) {
	Game* game = new Game(argv[0], 1024, 600);
	game->run();
	delete game;
	return 0;
}