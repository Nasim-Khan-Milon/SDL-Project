#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>


#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 700
double R=0;
SDL_Window *win = NULL;
SDL_Renderer *rend = NULL;
bool gameIsRunning=false;
int f=0;

int starting(){
if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
std::cout<<"Error: SDL failed to initialize\n"<<"SDL Error:"<<" "<<SDL_GetError()<<'\n';
return 0;
}


 win = SDL_CreateWindow("Increase the Circle Radius",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT, 0);
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
void decreasing_radious();
void incrising_radious()
{
R+=5;
if(R>=300) f=1;
}

void decreasing_radious()
{
    R-=5;
    if(R==0) f=0;
}

void  game_loop()
{
  SDL_Event e;

  while(SDL_PollEvent(&e))
     {
       if(e.type==SDL_QUIT) {gameIsRunning=false; break;}
     }

}


void createCircle( int centerX, int centerY, int radius) {
    for (int x = -radius; x <= radius; x++) {
        for (int y = -radius; y <= radius; y++) {
            if (x*x + y*y <= radius*radius) {
                SDL_RenderDrawPoint(rend, centerX + x, centerY + y);
            }
        }
    }
}
// void Draw()
// {

//     SDL_SetRenderDrawColor(rend, 150, 0, 200, 0);
// 	SDL_RenderClear(rend);
//     if(f==0) incrising_radious();
//     else decreasing_radious();
// 	SDL_SetRenderDrawColor(rend, 0, 120, 200, 0);
//     draw_Circle(SCREEN_WIDTH/2,SCREEN_HEIGHT/2,R);
// 	SDL_RenderPresent(rend);

// }


int main(int argc,char *argv[])
{
gameIsRunning=starting();

while(gameIsRunning)
{
	game_loop();
    SDL_SetRenderDrawColor(rend, 88, 198, 200, 0);
	SDL_RenderClear(rend);
    if(f==0) incrising_radious();
    else decreasing_radious();
	SDL_SetRenderDrawColor(rend, 210, 150, 30, 0);
    createCircle(SCREEN_WIDTH/2,SCREEN_HEIGHT/2,R);
	SDL_RenderPresent(rend);
}
SDL_DestroyWindow(win);
SDL_Quit();
return 0;
}