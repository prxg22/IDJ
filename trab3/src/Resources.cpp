#include "Resources.hpp"

#include <cstdio>

#include "Game.hpp"
#include "Texture.hpp"

Resources::Resources(){}
Resources::~Resources() {
	clear();
}
SDL_Texture* Resources::getImage(const std::string& file) {
	std::string path = Game::getInstance().getPath() + "/img/" + file;
	if(resourceTable.count(path)){
		Texture* image = (Texture*) resourceTable[path];
		return image->sdlTexture;
	}
	Texture* image = new Texture(path);
	if (image->sdlTexture == nullptr) {
		fprintf(stderr, "%s\n", SDL_GetError());
		delete image;
		return nullptr;
	}
	resourceTable[path] = image;
	return image->sdlTexture;
}
Tilemap* Resources::getTilemap(const std::string& file) {
	std::string path = Game::getInstance().getPath() + "/map/" + file;
	if(resourceTable.count(path)){
		return (Tilemap*) resourceTable[path];
	}
	Tilemap* tilemap = new Tilemap(path);
	resourceTable[path] = tilemap;
	return tilemap;
}
void Resources::clear() {
	for (auto& kv: resourceTable) {
		delete kv.second;
	}
}
