#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int TILE_SIZE = 10;
int bonusOn = 0;
int bonusCreateTime, p_time;
TTF_Font* font = nullptr; 

class Snake
{
public:
    Snake();
    void handleInput(SDL_Event &e);
    void move(SDL_Renderer *renderer);
    void render(SDL_Renderer *renderer);
    bool checkCollision();
    void grow();
    
    void bonusfood();
    
    
    bool checkcollisionbonus();
    
    
    void renderGameOver(SDL_Renderer *renderer);

    int score = 0;

private:
    SDL_Rect food;
    
    vector<SDL_Rect> body;
    
    int direction;
    
};

Snake::Snake()
{
    grow();
    direction = 3; // Start moving to the right
    
    spawnFood();
    
    eatsound = Mix_LoadWAV("toms-screams.mp3");
    if (!eatsound)
        cout << SDL_GetError() << endl;
}

void Snake::handleInput(SDL_Event &e) {
    // Check if a key was pressed
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_UP:
                // Prevent reversing into itself
                if (direction != 1) direction = 0;
                break;
            case SDLK_DOWN:
                if (direction != 0) direction = 1;
                break;
            case SDLK_LEFT:
                if (direction != 3) direction = 2;
                break;
            case SDLK_RIGHT:
                if (direction != 2) direction = 3;
                break;
        }
    }
}

