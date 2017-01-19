#ifndef WINDOW_ENTITY_H_INCLUDED
#define WINDOW_ENTITY_H_INCLUDED

#include<SDL2/SDL.h>

#include <string>

class SScreen{
	public:
		SScreen(std::string Name, const unsigned int Width, const unsigned int Height);
		~SScreen();
		SDL_Surface* Ref();
		SDL_Window* Get();
		SDL_Renderer* CreateRenderer();

	private:
		SDL_Window * Window;
};

class RScreen{
	public:
		RScreen(std::string Name, const unsigned int Width, const unsigned int Height);
		~RScreen();
		SDL_Surface* Ref();
		SDL_Window* Get();
		SDL_Renderer* CreateRenderer();
		unsigned int Height;
		unsigned int Width;

	private:
		SDL_Window* Window;
};

#endif // WINDOW_ENTITY_H_INCLUDED
