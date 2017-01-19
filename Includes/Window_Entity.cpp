#include "Window_Entity.h"

#include <stdio.h>

SScreen::SScreen(std::string Name, const unsigned int Width, const unsigned int Height){
	Window = SDL_CreateWindow(Name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height, SDL_WINDOW_SHOWN);
	if(Window == NULL)printf("[FAILED]\tSDL_CreateWindow(%s, %u, %u)\n\t Error:\t%s", Name.c_str(), Width, Height, SDL_GetError());
}

SScreen::~SScreen(){
	SDL_DestroyWindow(Window);
}

SDL_Surface* SScreen::Ref(){
	return SDL_GetWindowSurface(Window);
}

SDL_Window* SScreen::Get(){
	return Window;
}

SDL_Renderer* SScreen::CreateRenderer(){
	return SDL_CreateRenderer( Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
}

RScreen::RScreen(std::string Name, const unsigned int SWidth, const unsigned int SHeight){
	Window = SDL_CreateWindow(Name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SWidth, SHeight, SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
	if(Window == NULL)printf("[FAILED]\tSDL_CreateWindow(%s, %u, %u)\n\t Error:\t%s", Name.c_str(), SWidth, SHeight, SDL_GetError());
	else{Width = SWidth; Height = SHeight;}
}

RScreen::~RScreen(){
	SDL_DestroyWindow(Window);
}

SDL_Surface* RScreen::Ref(){
	return SDL_GetWindowSurface(Window);
}

SDL_Window* RScreen::Get(){
	return Window;
}

SDL_Renderer* RScreen::CreateRenderer(){
	return SDL_CreateRenderer( Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
}
