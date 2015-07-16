#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define WIDTH_WINDOW 800
#define HEIGHT_WINDOW 600
#define SDL_Rekt SDL_Rect

int move(SDL_Keycode , SDL_Rect*);



int main(){
	 
	SDL_Event event;
	SDL_Window* window;
	SDL_Surface* screen;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("yolo",
				 SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				 WIDTH_WINDOW, HEIGHT_WINDOW,
				 SDL_WINDOW_SHOWN);


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

	while(event.type != SDL_QUIT) {
	SDL_PollEvent(&event);
		if(event.key.keysym.sym) 
			move(event.key.keysym.sym, &positionSM2);	//Appel de la fonction modifié
									 
		
	SDL_BlitSurface(snowMan2, NULL, screen, &positionSM2);	
//	SDL_UpdateRect(screen);
	printf("X: %d \t Y: %d\n", positionSM2.x, positionSM2.y);


	}
	SDL_Quit();
}


int move(SDL_Keycode event, SDL_Rect* position){			//créé un pointeur sur Rect pour éliminer les returns	
	if (event == SDLK_z)						//transmission de l'évent - > un seul switch dans le code
		position->y ++;						
	else if (event == SDLK_d)
		position->x ++;
	else if (event == SDLK_s)
		position->y --;
	else if(event == SDLK_q)
		position->x --;
	else
		return -1;						//Touche non gérée
	}



