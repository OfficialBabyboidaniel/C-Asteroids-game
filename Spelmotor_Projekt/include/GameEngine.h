#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <vector>
#include "Sprites.h"
namespace cwing
{
    class GameEngine
    {
    private:
        std::vector<Sprites *> added, removed; // vector för temporära objekt som skapas under spelloopen, för att det ej går att addera obejkt till den SDL_Pollevent-loopen som körs
        std::vector<Sprites *> sprites;
    public:
        void add(Sprites *s);
        void remove(Sprites *s);
        void run();
        bool isCollided(Sprites *s1, Sprites *s2);
    };

}

#endif
