#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H
#include "Sprites.h"
#include "EnemyCharacter.h"
#include <vector>

namespace cwing
{

    class PlayerCharacter : public Sprites
    {
    private:
        SDL_Texture *texture;
    protected:
        PlayerCharacter(int x, int y, int w, int h, SDL_Texture *texture); // så att det inte kan skapas i stackan
    public:
        static PlayerCharacter *getInstance(int x, int y, int w, int h, SDL_Texture *texture);
        ~PlayerCharacter(); 
        void draw() const;
        void tick();
        void keyDown(const SDL_Event &); //Överskuggad funktion som gör någonting när en tangent är nedtryckt, se mer i CPP fil
        void setTexture(const char *file); //sätt texturen för spelaren
        // set texture
        // get teture
    };

}

#endif