#ifndef SPRITES_H
#define SPRITES_H
#include "SDL2/SDL.h"
namespace cwing
{
    class Sprites //klass för sprites som är beredd att vara en rotklass i n klassheirki 
    {
    protected:
        SDL_Rect rect;
        Sprites(int x, int y, int w, int h);
    private:
        Sprites(const Sprites &) = delete;                  // förbjuda tilldelning och kopierings möjligheter för att förebygga slicing effekt 
        const Sprites &operator=(const Sprites &) = delete; 
    public:
        virtual ~Sprites();
        virtual void mouseDown(int x, int y) {} // överskuggade funktioner för händelser som ska ske av användaren/spelaren och hur Objekt ska ritas (draw) ut och bete sig (tick) under spelets omgång
        virtual void mouseUp(int x, int y) {}
        virtual void keyDown(const SDL_Event &) {}
        virtual void keyUp(const SDL_Event &) {}
        virtual void draw() const = 0;
        virtual void tick() = 0;
        const SDL_Rect &get_rect() const { return rect; }
    };
}

#endif