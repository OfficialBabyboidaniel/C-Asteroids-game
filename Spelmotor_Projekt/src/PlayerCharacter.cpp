#include "PlayerCharacter.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <System.h>

namespace cwing
{
    PlayerCharacter *PlayerCharacter::getInstance(int x, int y, int w, int h, SDL_Texture* tex)
    {
        return new PlayerCharacter(x, y, w, h, tex);
    }

    PlayerCharacter::PlayerCharacter(int x, int y, int h, int w, SDL_Texture* tex) : Sprites(x, y, h, w), texture(tex)
    {
       
    }

    PlayerCharacter::~PlayerCharacter()
    {
        SDL_DestroyTexture(texture);
    }

    void PlayerCharacter::draw() const
    {
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &get_rect());

    }
    void PlayerCharacter::tick()
    {
        
    }

    //funktion som rör spelaren väsnter eller höger beroende på vilken tangent man trycker ner
    // a + d eller vänster pil och höger pil (rörelse/förflyttning i sidled)
    void PlayerCharacter::keyDown(const SDL_Event& event){ 

        if(event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_LEFT ){  
                rect.x-=10;
        } else if(event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT){
            rect.x +=10 ;
        }
    }

    void PlayerCharacter::setTexture(const char *file)
    {
        SDL_DestroyTexture(texture);
        texture = IMG_LoadTexture(sys.get_ren(), file);
    }
}
