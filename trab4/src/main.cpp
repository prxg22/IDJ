#include "Game.hpp"

int main(int argc, char** argv) {
	Game game(argv[0], 1024, 600);
	game.run();
	return 0;
}