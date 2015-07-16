#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define WIDTH_WINDOW 800
#define HEIGHT_WINDOW 600
#define SDL_Rekt SDL_Rect

int move(int, SDL_Rect);



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
		switch(event.key.keysym.sym){
		
		case SDLK_z:
			positionSM2.y = move(1, positionSM2);
			printf("position loop : %d \n", positionSM2.y);
			usleep(10000);		
		break;
		case SDLK_q:
			positionSM2.x = move(4, positionSM2); 
			usleep(10000);

		break;
		case SDLK_s:
			positionSM2.y = move(3, positionSM2);
			usleep(10000);
		break;
		case SDLK_d:
			positionSM2.x =  move(2, positionSM2);
			usleep(10000);

		break;
		default:
		break;


		}
	SDL_BlitSurface(snowMan2, NULL, screen, &positionSM2);	
	SDL_UpdateRect(screen);
	usleep(1000/30);


	}
	SDL_Quit();
}


int move(int direction, SDL_Rect position){

	// direction : 1 haut, 2 : droite, 3 : bas, 4 gauche
	switch(direction){
	
	case 1:
		printf("position : %d \tdirection : %d \n", position.y, direction);
		position.y ++;				
		return position.y;
	break;
	case 2:
		position.x ++;
		return position.x;
	break;
	case 3:
		position.y --;
		return position.y;
	break;
	case 4:
		position.x --;
		return position.x;
	break;
	default:
		return -1;
	break;
	}

}

