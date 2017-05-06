#include "Tilemap.hpp"

#include <fstream>
#include <cstdio>

#include "Game.hpp"

Tilemap::Tilemap(const std::string& path){
	std::fstream f(path);
	
	int setCols, setRows;
	std::string setName;
	f >> setCols;
	f.get();
	f >> setRows;
	f.get();
	f >> setName;
	tileset = new Tileset(setCols, setRows, setName);
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
Tilemap::~Tilemap(){
	delete tileset;
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

