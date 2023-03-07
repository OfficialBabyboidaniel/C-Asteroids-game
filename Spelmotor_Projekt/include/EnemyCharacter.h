#ifndef ENEMYCHARACTER_H
#define ENEMYCHARACTER_H
#include "Sprites.h"

namespace cwing
{

    class EnemyCharacter : public Sprites //liknande klassdesign som PlayerChar
    {
    private:
        int counter = 0; //används för tick funktionen, vid förflyttning neråt i banan
        SDL_Texture* texture;
    protected:
        EnemyCharacter(int x, int y, int h, int w, SDL_Texture* texture);
    public:
        static EnemyCharacter *getInstance(int x, int y, int w, int h, SDL_Texture* texture);
        ~EnemyCharacter();
        void draw() const;
        void tick();
        void setTexture(const char* file); 
    };

}

#endif
