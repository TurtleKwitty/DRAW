#ifndef DISPLAYABLE_IMAGE_ENTITY_H_INCLUDED
#define DISPLAYABLE_IMAGE_ENTITY_H_INCLUDED

#include <SDL.h>

#include <string>

class Image{
	public:
		Image();
		~Image();
		bool Load(std::string, SDL_Window*);
		SDL_Surface* Ref();

	private:
		SDL_Surface *Surface;
};

#endif // DISPLAYABLE_IMAGE_ENTITY_H_INCLUDED
