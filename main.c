#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define WIDTH_WINDOW 800
#define HEIGHT_WINDOW 600

int main(){
	 
	SDL_Event quit;
	SDL_Window* window;
	SDL_Surface* screen;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("yolo",
				 SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				 WIDTH_WINDOW, HEIGHT_WINDOW,
				 SDL_WINDOW_SHOWN);
	
	screen = SDL_GetWindowSurface(window);

	SDL_Surface *snowMan1 = IMG_Load("snowmanB.png");
	SDL_Surface *snowMan2 = IMG_Load("snowmanB.png");
	SDL_Rect positionSM1;
	SDL_Rect positionSM2;

	positionSM1.x = (WIDTH_WINDOW / 2) - (WIDTH_WINDOW / 4);  
	positionSM1.y = HEIGHT_WINDOW / 2;

	positionSM2.x = (WIDTH_WINDOW / 2) + (WIDTH_WINDOW / 4);
	positionSM2.y = HEIGHT_WINDOW / 2;
	

	SDL_BlitSurface(snowMan1, NULL, screen, &positionSM1);	
	SDL_BlitSurface(snowMan2, NULL, screen, &positionSM2);
	SDL_UpdateWindowSurface(window);

	while(quit.type != SDL_QUIT) {
	SDL_PollEvent(&quit);
		
	
		




	 
	
	}

	SDL_Quit();




}
