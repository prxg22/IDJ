#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <unordered_map>
#include <string>
#include <SDL2/SDL.h>

#include "Tilemap.hpp"

class ResourceManager
{
private:
	std::unordered_map<std::string, Resource*> resourceTable;
public:
	ResourceManager();
	~ResourceManager();
	SDL_Texture* getImage(const std::string& file);
	Tilemap* getTilemap(const std::string& file);
	void clear();
};

#endif