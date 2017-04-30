#include "Sprite.hpp"

#include <cstdio>

#include <SDL2/SDL_image.h>

#include "Game.hpp"


Sprite::Sprite() : texture(nullptr) {
	
}

Sprite::Sprite(const std::string& file_name) : texture(nullptr) {
	open(file_name);
}

Sprite::~Sprite() {
	close();
}

void Sprite::open(const std::string& file_name) {
	close();
	texture = IMG_LoadTexture(Game::getInstance().getRenderer(),file_name.c_str());
	if (texture == nullptr) {
		fprintf(stderr, "%s\n", SDL_GetError());
		return;
	}
	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
	setClip(0, 0, width, height);
}

void Sprite::setClip(int x, int y, int w, int h){
	clipRect = {x, y, w, h};
}


void Sprite::close() {
	if (texture) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

void Sprite::render(int x, int y) const {
	SDL_Rect rect = {x, y, clipRect.w, clipRect.h};
	SDL_RenderCopy(Game::getInstance().getRenderer(), texture, &clipRect, &rect);
}

int Sprite::getWidth() const {
	return width;
}

int Sprite::getHeight() const {
	return height;
}

bool Sprite::isOpen() const {
	return texture != nullptr;
}