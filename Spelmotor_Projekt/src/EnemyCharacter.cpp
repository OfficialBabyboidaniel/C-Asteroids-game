#include "EnemyCharacter.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <System.h>

namespace cwing
{

    EnemyCharacter *EnemyCharacter::getInstance(int x, int y, int w, int h, SDL_Texture *tex)
    {

        return new EnemyCharacter(x, y, w, h, tex);
    }

    EnemyCharacter::EnemyCharacter(int x, int y, int h, int w, SDL_Texture *tex) : Sprites(x, y, h, w), texture(tex)
    {
    }

    EnemyCharacter::~EnemyCharacter()
    {
        SDL_DestroyTexture(texture);
    }

    void EnemyCharacter::draw() const
    {
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &get_rect());
    }

    // flyttar ner enemyObjekt när counter vilkoret uppfyllts (annars flyttas den ner för snabbt)
    void EnemyCharacter::tick()
    {
        counter++;
        if (counter % 60 == 0)
        {
            rect.y++;
        }
    }

    void EnemyCharacter::setTexture(const char *file)
    {
        SDL_DestroyTexture(texture);
        texture = IMG_LoadTexture(sys.get_ren(), file);
    }
}
