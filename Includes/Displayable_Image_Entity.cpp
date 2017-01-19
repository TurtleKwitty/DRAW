#include "Displayable_Image_Entity.h"

#include <SDL.h>

#include <stdio.h>
#include <string>

Image::Image():Surface(NULL){;}
Image::~Image(){SDL_FreeSurface(Surface);}
bool Image::Load(std::string Location, SDL_Window* Main){
	SDL_Surface* TEMP_SURFACE;
	if((TEMP_SURFACE = SDL_LoadBMP(("Images/" + Location).c_str())) == NULL){
		printf("[FAILED]\tSDL_LoadBMP(%s)\n\tError: %s", Location.c_str(), SDL_GetError());
		return false;
	}
	else{
		if((Surface = SDL_ConvertSurface(TEMP_SURFACE, SDL_GetWindowSurface(Main)->format, NULL)) == NULL){
			printf("[FAILED]\tSDL_ConvertSurface(%s)\n\tError: %s", Location.c_str(), SDL_GetError());
			return false;
		}
		SDL_FreeSurface(TEMP_SURFACE);
	}
}
SDL_Surface* Image::Ref(){return Surface;}