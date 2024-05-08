#include<iostream>
#include<SDL2/SDL.h>
using namespace std;

int main(int argc,char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("Hello SDL world.",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,500,500,SDL_WINDOW_ALLOW_HIGHDPI);
    if(window==NULL)
    {
        cout<<"NO window"<<SDL_GetError()<<endl;
        return 1;
    }
    else
      cout<<"Window Opened!!!";
    bool game = true;
   SDL_Event windowevent;
    while(game)
    {  
    

      if(SDL_PollEvent(&windowevent))
        {
            if(SDL_QUIT==windowevent.type)
                break;

             //if(windowevent==SDL_MOUSEMOTION)
             //cout<<"MOUSE!";
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit( );
    return EXIT_SUCCESS;
}