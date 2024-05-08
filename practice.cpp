#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 700
#define R 150
SDL_Window *win = NULL;
SDL_Renderer *rend = NULL;
bool gameIsRunning=false;


int initializing(){
if(SDL_Init(SDL_INIT_VIDEO)!=0){
std::cout<<"Error: SDL failed to initialize\n"<<"SDL Error:"<<" "<<SDL_GetError()<<'\n';
return 0;
}


 win = SDL_CreateWindow("Drawing Circle",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT, 0);
if (!win)
    {
       std::cout<<"Error: SDL failed to open window\n"<<"SDL Error:"<<" "<<SDL_GetError()<<'\n';
       return 0;;
    }



    rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (!rend)
    {
        std::cout<<"Error: SDL failed to create renderer\n"<<"SDL Error:"<<" "<<SDL_GetError()<<'\n';
        return 0;;
    }

	return 1;
}

void  event_loop()
{
  SDL_Event event;

  while(SDL_PollEvent(&event))
     {
       if(event.type==SDL_QUIT) {gameIsRunning=false; break;}
     }

}


void draw_Circle( int centerX, int centerY, int radius) {
    for (int x = -radius; x <= radius; x++) {
        for (int y = -radius; y <= radius; y++) {
            if (x*x + y*y <= radius*radius) {
                SDL_RenderDrawPoint(rend, centerX + x, centerY + y);
            }
        }
    }
}

int main(int argc,char *argv[])
{
gameIsRunning=initializing();

while(gameIsRunning)
{
	event_loop();
    SDL_SetRenderDrawColor(rend, 0, 255, 0, 0);
	SDL_RenderClear(rend);
	SDL_SetRenderDrawColor(rend, 250, 0, 0, 0);
    draw_Circle(SCREEN_WIDTH/2,SCREEN_HEIGHT/2,R);
	SDL_RenderPresent(rend);
}
SDL_DestroyWindow(win);
SDL_Quit();
return 0;
}