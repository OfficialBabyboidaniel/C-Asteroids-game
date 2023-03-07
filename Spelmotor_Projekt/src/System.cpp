#include "System.h"
#include <SDL2/SDL.h>
namespace cwing{

    System::System(){
        SDL_Init(SDL_INIT_EVERYTHING);
        win = SDL_CreateWindow("Cwing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0); //screen size bör ändra sen
        ren = SDL_CreateRenderer(win, -1, 0);


    }

    System::~System(){
        SDL_DestroyWindow(win);
        SDL_DestroyRenderer(ren);
        SDL_Quit();
    }

    SDL_Renderer* System::get_ren() const {
        return ren;
    }
    System sys;
}