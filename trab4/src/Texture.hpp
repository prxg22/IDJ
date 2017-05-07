#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>
#include <SDL2/SDL.h>

#include "Resource.hpp"

class Texture : public Resource {
public:
	SDL_Texture* sdlTexture;
	Texture(const std::string& path);
	~Texture();
};

#endif