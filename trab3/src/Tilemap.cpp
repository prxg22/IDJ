#include "Tilemap.hpp"

#include <fstream>
#include <cstdio>

#include "Game.hpp"

Tilemap::Tilemap(const std::string& file, Tileset* tileset){
	load(file);
	setTileset(tileset);
}

void Tilemap::load(const std::string& file) {
	std::string path = Game::getInstance().getPath() + "/map/" + file;
	std::fstream f(path);
	f >> width;
	f.get(); // tira a virgula
	f >> height;
	f.get();
	f >> depth;
	f.get();
	
	int index;
	for(int z = 0; z < depth; z++){
		for(int y = 0; y < height; y++){
			for(int x = 0; x < width; x++){
				f >> index;
				tileMatrix.push_back(index-1);
				f.get();
			}
		}
	}
}

void Tilemap::setTileset(Tileset* tileset) {
	this->tileset = tileset;
}

void Tilemap::render(int cameraX, int cameraY) {
	for(int z = 0; z < depth; z++){
		renderLayer(z, cameraX, cameraY);
	}
}

void Tilemap::renderLayer(int layer, int cameraX, int cameraY) {
	int screenX;
	for(int y = 0; y < height; y++){
		screenX = cameraX;
		for(int x = 0; x < width; x++) {
			tileset->render(at(x, y, layer), screenX, cameraY);
			screenX += tileset->getTileWidth();
		}
		cameraY += tileset->getTileHeight();
	}
}

int Tilemap::getWidth() const{
	return width;
}

int Tilemap::getHeight() const{
	return height;
}

int Tilemap::getDepth() const{
	return depth;
}

