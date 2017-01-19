/** Includes: Libraries **/
#include <SDL.h>

/** Includes: Tools **/
#include <stdio.h>

/** Includes: Personal **/
#include "Includes/Window_Entity.h"
#include "Includes/Displayable_Image_Entity.h"

/** Window Variables: Resolution **/
const unsigned int WV_Width = 800;
const unsigned WV_Height = 600;

/** SDL Variables **/
SDL_Event Events;

/** Program Variables **/
bool Quit = false;
int Menus_Deep = 0;
bool Draw = false;
bool AutoDraw = false;
bool ClickDraw = true;

bool ColorChanged = true;

Uint8 Color_Palette [(	68	*3)+1] = {
			68			-1,
0xFF,	0xFF,	0xFF,
0xb0, 0xb0, 0xb0,
0x80,	0x80,	0x80,
0x40, 0x40, 0x40,
0x00,	0x00,	0x00,

0xFF, 0x00, 0x00,
0x00, 0xFF, 0x00,
0x00, 0x00, 0xFF,

0xFF, 0xFF, 0x00,
0x00, 0xFF, 0xFF,
0xFF, 0x00, 0xFF,

0x40, 0x00, 0x00,
0x80, 0x00, 0x00,
0xb0, 0x00, 0x00,
0xFF,	0x00, 0x00,
0xFF, 0x40, 0x00,
0xFF, 0x40, 0x40,
0xFF, 0x80, 0x00,
0xFF, 0x80, 0x40,
0xFF, 0x80, 0x80,
0xFF, 0xb0, 0x00,
0xFF, 0xb0, 0x40,
0xFF, 0xb0, 0x80,
0xFF, 0xb0, 0xb0,
0xFF, 0x80, 0xb0,
0xFF, 0x40, 0xb0,
0xFF, 0x00, 0xb0,
0xFF, 0x40, 0x80,
0xFF, 0x00, 0x80,
0xFF, 0x00, 0x40,

0x00, 0x40, 0x00,
0x00, 0x80, 0x00,
0x00, 0xb0, 0x00,
0x00, 0xFF, 0x00,
0x40, 0xFF, 0x00,
0x40, 0xFF, 0x40,
0x80, 0xFF, 0x00,
0x80, 0xFF, 0x40,
0x80, 0xFF, 0x80,
0xb0, 0xFF, 0x00,
0xb0, 0xFF, 0x40,
0xb0, 0xFF, 0x80,
0xb0, 0xFF, 0xb0,
0x80, 0xFF, 0xb0,
0x40, 0xFF, 0xb0,
0x00, 0xFF, 0xb0,
0x40, 0xFF, 0x80,
0x00, 0xFF, 0x80,
0x00, 0xFF, 0x40,

0x00, 0x00, 0x40,
0x00, 0x00, 0x80,
0x00, 0x00, 0xb0,
0x00, 0x00, 0xFF,
0x40, 0x00, 0xFF,
0x40, 0x40, 0xFF,
0x80, 0x00, 0xFF,
0x80, 0x40, 0xFF,
0x80, 0x80, 0xFF,
0xb0, 0x00, 0xFF,
0xb0, 0x40, 0xFF,
0xb0, 0x80, 0xFF,
0xb0, 0xb0, 0xFF,
0x80, 0xb0, 0xFF,
0x40, 0xb0, 0xFF,
0x00, 0xb0, 0xFF,
0x40, 0x80, 0xFF,
0x00, 0x80, 0xFF,
0x00, 0x40, 0xFF,
};

bool DrawModeF = false;
bool DrawModeE = false;

SDL_Rect Rect = {41,0,WV_Width,WV_Height};
SDL_Rect Color_View = {2,WV_Height - 2,38,-10};
SDL_Rect Color_ViewR = {2,WV_Height - 24,10,-512};
SDL_Rect Color_ViewG = {16,WV_Height - 24,10,-512};
SDL_Rect Color_ViewB = {30,WV_Height - 24,10,-512};

SDL_Rect Color_Highlight = {0,WV_Height - 12,10,-10};
SDL_Rect Mode_View = {5,5,30,30};
SDL_Rect AutoView = {5,40,30,WV_Height - 581};
SDL_Rect Selector = {0,565,0,33};
SDL_Rect ClickView = {29,1,10,10};

Uint8 ColorR = 0x80;
Uint8 ColorG = 0x80;
Uint8 ColorB = 0x80;
Uint8 ColorA = 0xFF;
bool Current_ColorB = false;
bool Current_ColorG = false;

/** Main **/
int main(int argc, char* argv[]){
	Menus_Deep++;

		/** Init SDL **/
	if(SDL_Init(SDL_INIT_VIDEO) < 0)printf( "SDL was unable to initialize.\n\t Error:\t%s", SDL_GetError());
	else{
			/** Init Window **/
		SScreen S_Main("DRAW's Really A Warmachine", WV_Width, WV_Height);
		SDL_Renderer* R_Main = NULL;
		R_Main = S_Main.CreateRenderer();
		if(R_Main == NULL){return Menus_Deep;}
		SDL_SetRenderDrawColor(R_Main, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderDrawLine(R_Main, Mode_View.x, Mode_View.y, Mode_View.w, Mode_View.h);
		SDL_RenderPresent(R_Main);
			/** Main Loop: Setup **/
			/** Main Loop: Run Loop **/
		while(Menus_Deep){
				/** Handle SDL Events **/
			while(SDL_PollEvent(&Events) != 0){
					/** X out Window **/
				if(Events.type == SDL_QUIT){Menus_Deep--;}
					/** Key Press **/
				else if(Events.type == SDL_KEYDOWN){
					switch(Events.key.keysym.sym){
						case SDLK_ESCAPE:
							SDL_SetRenderDrawColor(R_Main, 0,0,0,0);
							SDL_RenderClear(R_Main);
							Draw = false;
							break;
						case SDLK_SPACE:
							Draw = !Draw;
							break;
						case SDLK_w:
							if(Current_ColorB == true && ColorB != 0xFF)ColorB++;
							else if(Current_ColorG == true && ColorG != 0xFF)ColorG++;
							else if(Current_ColorB == false && Current_ColorG == false && ColorR != 0xFF)ColorR++;
							ColorChanged = true;
							break;
						case SDLK_s:
							if(Current_ColorB == true && ColorB != 0)ColorB--;
							else if(Current_ColorG == true && ColorG != 0)ColorG--;
							else if(Current_ColorB == false && Current_ColorG == false && ColorR != 0)ColorR--;
							ColorChanged = true;
							break;
						case SDLK_a:
							SDL_SetRenderDrawColor(R_Main, 0,0,0,0);
							if(Current_ColorB == true){SDL_RenderFillRect(R_Main, &Color_Highlight);Current_ColorG = true; Current_ColorB = false;}
							else if(Current_ColorG == true){SDL_RenderFillRect(R_Main, &Color_Highlight); Current_ColorG = false;}
							else {SDL_RenderFillRect(R_Main, &Color_Highlight);Current_ColorB = true;}
							break;
						case SDLK_d:
							if(DrawModeF == true){DrawModeE = true; DrawModeF = false;}
							else if(DrawModeE == true){DrawModeE = false;}
							else {DrawModeF = true;}
					}
				}
					/** Mouse Events **/
				else if(Events.type == SDL_MOUSEMOTION){
					SDL_GetMouseState(&Rect.w, &Rect.h);
					if(DrawModeE || DrawModeF){Rect.w -= Rect.x; Rect.h -= Rect.y;}
					else{if(Rect.w <=40){Rect.w = 41;}if(Rect.h >= 560){Rect.h = 559;}}
				}
				else if(Events.type == SDL_MOUSEBUTTONDOWN){
					if(Rect.w >= 41 && Rect.y <= 559 && DrawModeE == false && DrawModeF == false && Draw == true && ClickDraw == true){SDL_SetRenderDrawColor(R_Main, ColorR, ColorG, ColorB, ColorA); SDL_RenderDrawLine(R_Main, Rect.x, Rect.y, Rect.w, Rect.h);}
					SDL_GetMouseState(&Rect.x, &Rect.y);
					Rect.w = Rect.h = 0;
					if(Rect.x <= 40){
						if(DrawModeE == false && DrawModeF == false && Rect.x >= 29 && Rect.x <= 39 && Rect.y >= 1 && Rect.y <= 11){ClickDraw = !ClickDraw;}
						if(Rect.x >= 5 && Rect.x <= 35 && Rect.y >= 40 && Rect.y <= 59){AutoDraw = !AutoDraw;}
						Rect.x = 41;
					}
					if(Rect.y >= 560){
						if(Rect.y >= 565 && Rect.y <= 598){
							for (int Color_Check = Color_Palette[0]; Color_Check >= 0; Color_Check--){
								if(Rect.x >= 47 + (Color_Check)*Selector.w + Color_Check*2 && Rect.x <= 47 + (Color_Check)*Selector.w + Color_Check*2 + ((756 - ((Color_Palette[0]) * 2)) / (Color_Palette[0] + 1))){
									ColorR = Color_Palette[(Color_Check*3) + 1];
									ColorG = Color_Palette[(Color_Check*3) + 2];
									ColorB = Color_Palette[(Color_Check*3) + 3];
								}
							}
						}
						Rect.y = 559;
					}
				}
			}

			if(Draw == true){
				SDL_SetRenderDrawColor( R_Main, ColorR, ColorG, ColorB, ColorA);
				if(DrawModeE){
					if((Rect.x + Rect.w) <= 40){Rect.w = 41 - Rect.x;}
					if((Rect.y + Rect.h) >= 560){Rect.h = 559 - Rect.y;}
					SDL_RenderDrawRect(R_Main, &Rect);
				}
				else if(DrawModeF){
					if((Rect.x + Rect.w) <= 40){Rect.w = 41 - Rect.x;}
					if((Rect.y + Rect.h) >= 560){Rect.h = 559 - Rect.y;}
					SDL_RenderFillRect(R_Main, &Rect);
				}
				else if(ClickDraw == false){SDL_RenderDrawLine(R_Main, Rect.x, Rect.y, Rect.w, Rect.h);}
				if(AutoDraw == false){Draw = false;}
			}

			/** Color View **/
			SDL_SetRenderDrawColor(R_Main, 0, 0, 0, 0xFF);
			SDL_RenderFillRect(R_Main, &Color_ViewB);
			SDL_RenderFillRect(R_Main, &Color_ViewG);
			SDL_RenderFillRect(R_Main, &Color_ViewR);
			Color_ViewB.h = 0-(2*ColorB);
			SDL_SetRenderDrawColor(R_Main, 0, 0, ColorB, 0xFF);
			SDL_RenderFillRect(R_Main, &Color_ViewB);
			Color_ViewG.h = 0-(2*ColorG);
			SDL_SetRenderDrawColor(R_Main, 0, ColorG, 0, 0xFF);
			SDL_RenderFillRect(R_Main, &Color_ViewG);
			Color_ViewR.h = 0-(2*ColorR);
			SDL_SetRenderDrawColor(R_Main, ColorR, 0, 0, 0xFF);
			SDL_RenderFillRect(R_Main, &Color_ViewR);

			/** Color Select **/
			Selector.w = ((756 - ((Color_Palette[0]) * 2)) / (Color_Palette[0] + 1));
			for (int Color_Count = Color_Palette[0]; Color_Count >= 0; Color_Count--){
				Selector.x = 47 + (Color_Count)*Selector.w + Color_Count*2;
				SDL_SetRenderDrawColor(R_Main, Color_Palette[(Color_Count*3) + 1], Color_Palette[(Color_Count*3) + 2], Color_Palette[(Color_Count*3) + 3], 0xFF);
				SDL_RenderFillRect(R_Main, &Selector);
			}


			/** Current Color **/
			if(Current_ColorB == true){Color_Highlight.x = 30;}
			else if(Current_ColorG == true){Color_Highlight.x = 16;}
			else {Color_Highlight.x = 2;}

			/** AutoDraw/ClickDraw View **/
			if(AutoDraw == true)SDL_SetRenderDrawColor(R_Main, 0,0xFF,0,0xFF);
			else if (AutoDraw == false) SDL_SetRenderDrawColor(R_Main, 0xFF,0,0,0xFF);
			SDL_RenderFillRect(R_Main, &AutoView);

			if(DrawModeE == false && DrawModeF == false){
				if(ClickDraw == true){
					switch(AutoDraw){
						case false:
							SDL_SetRenderDrawColor(R_Main, 0x00, 0xFF, 0x00, 0xFF);
					}
				}
				else{
					switch(AutoDraw){
						case true:
							SDL_SetRenderDrawColor(R_Main, 0xFF, 0x00, 0x00, 0xFF);
					}
				}
			}
			else{SDL_SetRenderDrawColor(R_Main, 0x00, 0x00, 0x00, 0xFF);}
			SDL_RenderFillRect(R_Main, &ClickView);

			/** Mode View **/
			SDL_SetRenderDrawColor(R_Main, 0, 0, 0, 0xFF);
			SDL_RenderFillRect(R_Main, &Mode_View);
			SDL_SetRenderDrawColor(R_Main, 0xFF, 0xFF, 0xFF, 0xFF);
			if(DrawModeE)SDL_RenderDrawRect(R_Main, &Mode_View);
			else if(DrawModeF)SDL_RenderFillRect(R_Main, &Mode_View);
			else SDL_RenderDrawLine(R_Main, Mode_View.x, Mode_View.y, Mode_View.w, Mode_View.h);

			SDL_SetRenderDrawColor( R_Main, ColorR, ColorG, ColorB, ColorA);
			SDL_RenderFillRect(R_Main, &Color_View);
			SDL_RenderFillRect(R_Main, &Color_Highlight);
			SDL_RenderPresent(R_Main);
		}
			/** Close SDL **/
			SDL_DestroyRenderer(R_Main);

		SDL_Quit();
	}

	return Menus_Deep;
}
