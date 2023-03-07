#include "GameEngine.h"
#include <SDL2/SDL.h>
#include "System.h"
#include "Sprites.h"
namespace cwing
{

    void GameEngine::add(Sprites *s) // adderar nya sprites i en temporär vector som sedan ska läggas till i gameloopen
    {
        added.push_back(s);
    }
    void GameEngine::remove(Sprites *s) // adderar gamla sprites som ska tas bort i en temporär vector som sedan ska tas bort från gameloopen
    {
        removed.push_back(s);
    }
    bool GameEngine::isCollided(Sprites *s1, Sprites *s2)
    {
        if (SDL_HasIntersection(&s1->get_rect(), &s2->get_rect()))
        {
            remove(s1);
            remove(s2);
            return true;
        }
        else
        {
            return false;
        }
    }

    void GameEngine::run()
    {
        bool quit = false;

        while (!quit)
        {
            SDL_Event eve;
            while (SDL_PollEvent(&eve))
            {
                switch (eve.type)
                {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    for (Sprites *s : sprites)
                    {
                        s->mouseDown(eve.button.x, eve.button.y);
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    for (Sprites *s : sprites)
                    {
                        s->mouseUp(eve.button.x, eve.button.y);
                    }
                    break;
                case SDL_KEYDOWN:
                    for (Sprites *s : sprites)
                    {
                        s->keyDown(eve);
                    }
                    break;
                case SDL_KEYUP:
                    for (Sprites *s : sprites)
                    {
                        s->keyUp(eve);
                    }
                    break;
                default:
                    break;
                }                      // switch
            }                          // inre while
            for (Sprites *s : sprites) // anropa "tick" funktion för alla sprite objekt, tick funktionen förändrar vissa elements tillstånd under gameloopen
            {
                s->tick();
            }

            for (Sprites *s : added) // addera nya sprites under loopen
            {
                sprites.push_back(s);
            }
            added.clear();

            for (Sprites *s : removed) // tar bort dynamisk allokerat minne under spelloopen, ex bulllets eller enemies, genom en iterator
            {
                for (std::vector<Sprites *>::iterator i = sprites.begin(); i != sprites.end();)
                {
                    if (*i == s)
                    {
                        i = sprites.erase(i);
                    }
                    else
                    {
                        i++;
                    }
                }
            }
            removed.clear();

            SDL_RenderClear(sys.get_ren());
            for (Sprites *s : sprites)
            {
                s->draw();
            }
            SDL_RenderPresent(sys.get_ren());

        } // yttre while
    }
}
