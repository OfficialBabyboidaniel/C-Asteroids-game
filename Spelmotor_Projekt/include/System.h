#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL2/SDL.h>
namespace cwing{

    class System
    {
    private:
    SDL_Window* win;
    SDL_Renderer* ren;
        /* data */
    public:
        System(/* args */);
        ~System();
        SDL_Renderer* get_ren() const;
    };
    

    extern System sys;
}


#endif