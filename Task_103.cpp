#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 700
int R=60;
SDL_Window *win = NULL;
SDL_Renderer *rend = NULL;
bool gameIsRunning=false;
//for first circle
int X=-R;
int Y=SCREEN_HEIGHT/2;
//for second circle
int x=SCREEN_WIDTH/2;
int y=SCREEN_HEIGHT-R;
bool col=false;
int r_color=200;
int  g_color=50;
int  f=0;
int c=0;

int starting(){
    if(SDL_Init(SDL_INIT_VIDEO)!=0){
        std::cout<<"Error: SDL failed to initialize\n"<<"SDL Error:"<<" "<<SDL_GetError()<<'\n';
        return 0;
    }

    win = SDL_CreateWindow("Collision between the two circle",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT, 0);
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


bool collision(int x,int y,int X,int Y)
{
    int d;
    d=(x-X)*(x-X)+(y-Y)*(y-Y);
    d=SDL_sqrt(d);
    if(d<=2*R) return true;
    return false;
}



void update()
{
    if(collision(x,y,X,Y)) {
        
        X=-R;r_color=50;g_color=200;
        if(f==0){r_color=50;g_color=200;f=1;}
        else {r_color=200;g_color=50;f=0;}
        
    }

    else
    {
        X+=4;c=0;
        if(X>=SCREEN_WIDTH+R) X=0;
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


void  game_loop()
{
  SDL_Event e;

  while(SDL_PollEvent(&e))
     {
       if(e.type==SDL_QUIT) {gameIsRunning=false; break;}
       else if (e.type == SDL_KEYDOWN) {
                        if(e.key.keysym.sym==SDLK_UP) 
                        {
                            y-=10;
                            if(y==R) {x=SCREEN_WIDTH/2;y=SCREEN_HEIGHT-R;}
                        }
                        if(e.key.keysym.sym== SDLK_DOWN)
                        {
                             y+=10;
                            if(y+R>SCREEN_HEIGHT) {x=SCREEN_WIDTH/2;y=SCREEN_HEIGHT-R;}

                        }
                        if(e.key.keysym.sym== SDLK_LEFT)
                        {
                            x-=10;
                            if(x==R) {x=SCREEN_WIDTH/2;y=SCREEN_HEIGHT-R;}
                             
                        }
                        if(e.key.keysym.sym==SDLK_RIGHT)
                        {
                          
                            x+=10;
                            if(x+R==SCREEN_WIDTH) {x=SCREEN_WIDTH/2;y=SCREEN_HEIGHT-R;}
                        }
                    }
     
     }

}


int main(int argc,char *argv[])
{
    gameIsRunning=starting();

    while(gameIsRunning)
    {
        game_loop();
        SDL_SetRenderDrawColor(rend, 88, 198, 200, 0);
        SDL_RenderClear(rend);

        update();

        SDL_SetRenderDrawColor(rend, r_color, g_color, 0, 0);
        createCircle(X,Y,R);

        SDL_SetRenderDrawColor(rend, g_color, r_color, 0, 0);
        createCircle(x,y,R);
        SDL_RenderPresent(rend);
    }

    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}