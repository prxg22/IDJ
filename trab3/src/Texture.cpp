#include "Texture.hpp"

#include <SDL2/SDL_image.h>

#include "Game.hpp"

Texture::Texture(const std::string& path) {
	sdlTexture = IMG_LoadTexture(Game::getInstance().getRenderer(),path.c_str());
}

Texture::~Texture() {
	SDL_DestroyTexture(sdlTexture);
}