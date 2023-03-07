#include "Constants.h" //gResPath-contains path to your resources.
#include <SDL2/SDL.h>
#include "GameEngine.h"
#include "Sprites.h"
#include <SDL2/SDL_image.h>
#include "System.h"
#include "EnemyCharacter.h"
#include "PlayerCharacter.h"
#include "iostream"
using namespace cwing;
GameEngine eng;

class Bullet : public Sprites
{
public:
	static Bullet *getInstance(int x)
	{
		return new Bullet(x);
	}
	Bullet(int x) : Sprites(x, 460, 40, 40)
	{
		texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/beams.png").c_str());
	}
	~Bullet()
	{
		SDL_DestroyTexture(texture);
	}
	void draw() const
	{
		SDL_RenderCopy(sys.get_ren(), texture, NULL, &get_rect());
	}
	void tick()
	{
		counter++;
		if (rect.y <= -50)
			eng.remove(this);
		else if (counter % 10 == 0)
			rect.y--;
	}

private:
	SDL_Texture *texture;
	int counter = 0;
};

class Pistol : public Sprites
{
private:
	int counter = 0;
	std::vector<Sprites *> bullets;

protected:
	Pistol() : Sprites(0, 0, 0, 0) {}

public:
	static Pistol *getInstance() { return new Pistol; }
	void draw() const {}
	void tick()
	{
		counter++;
	}
	void mouseDown(int x, int y)
	{
		if (counter > 5)
		{
			Bullet *b = Bullet::getInstance(x);
			bullets.push_back(b);
			eng.add(b);
			counter = 0;
		}
	}
	std::vector<Sprites *> &get_bullets() { return bullets; }
};

class EnemySpawner : public Sprites
{
private:
	int counter = 0;
	SDL_Texture *tex;
	std::vector<Sprites *> enemies;

protected:
	EnemySpawner() : Sprites(0, 0, 0, 0) {}

public:
	static EnemySpawner *getInstance() { return new EnemySpawner; }
	void draw() const {}
	void tick()
	{
		int lower = 0, upper = 700;
		counter++;
		if (counter % 3000 == 0)
		{
			tex = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/asteroid.png").c_str());
			EnemyCharacter *e = EnemyCharacter::getInstance((rand() % (upper - lower + 1)), 0, 75, 75, tex);
			eng.add(e);
			enemies.push_back(e);
		}
		int enemyCounter = 0;
		for (std::vector<Sprites *>::iterator i = enemies.begin(); i != enemies.end();)
		{
			if (enemies.at(enemyCounter)->get_rect().y == 700) // ändra om så ifall den träffar playercharacter
			{
				eng.remove(enemies.at(enemyCounter));
				i = enemies.erase(i);
				i++;
			}
			else
			{
				i++;
			}
			enemyCounter++;
		}
		enemyCounter = 0;
	}
	std::vector<Sprites *> &get_enemies() { return enemies; }

private:
};

class PlayerState : public Sprites
{
private:
	PlayerCharacter *p;
	EnemySpawner *e;
	Pistol *pistol;

protected:
	PlayerState(PlayerCharacter *playerCharacter, EnemySpawner *enemySpawner, Pistol *pis) : Sprites(0, 0, 0, 0), p(playerCharacter), e(enemySpawner), pistol(pis) {}

public:
	static PlayerState *getInstance(PlayerCharacter *p, EnemySpawner *e, Pistol *pis) { return new PlayerState(p, e, pis); }
	void draw() const {}
	void tick()
	{
		int enemyCounter = 0;
		for (std::vector<Sprites *>::iterator i = e->get_enemies().begin(); i != e->get_enemies().end();)
		{
			if (eng.isCollided(p, e->get_enemies().at(enemyCounter))) // ändra om så ifall den träffar playercharacter
			{
				i = e->get_enemies().erase(i);
				eng.remove(pistol);
				i++;
			}
			else
			{
				i++;
			}
			enemyCounter++;
		}
		enemyCounter = 0;
	}
};

class EnemyState : public Sprites
{
private:
	Pistol *pistol;
	EnemySpawner *enemies;

protected:
	EnemyState(Pistol *p, EnemySpawner *e) : Sprites(0, 0, 0, 0), pistol(p), enemies(e) {}

public:
	static EnemyState *getInstance(Pistol *p, EnemySpawner *e) { return new EnemyState(p, e); }
	void draw() const {}
	void tick()
	{
		int enemyCounter = 0;
		int bulletCounter = 0;
		for (std::vector<Sprites *>::iterator i = enemies->get_enemies().begin(); i != enemies->get_enemies().end();)
		{
			for (std::vector<Sprites *>::iterator e = pistol->get_bullets().begin(); e != pistol->get_bullets().end();)
			{

				if (eng.isCollided(enemies->get_enemies().at(enemyCounter), pistol->get_bullets().at(bulletCounter))) // ändra om så ifall den träffar playercharacter
				{
					e = pistol->get_bullets().erase(e);
					i = enemies->get_enemies().erase(i);
					e++;
					return;
				}
				else
				{
					e++;
				}
				bulletCounter++;
			}
			bulletCounter = 0;
			i++;
			enemyCounter++;
		}
		enemyCounter = 0;
	}
};

int main(int argc, char **argv)
{
	SDL_Texture *tex = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/SpeceShip2.png").c_str());
	Pistol *pistol = Pistol::getInstance();
	EnemySpawner *enemies = EnemySpawner::getInstance();
	PlayerCharacter *p = PlayerCharacter::getInstance(350, 500, 100, 100, tex);
	PlayerState *playerState = PlayerState::getInstance(p, enemies, pistol);
	EnemyState *enemyState = EnemyState::getInstance(pistol, enemies);
	eng.add(enemyState);
	eng.add(playerState);
	eng.add(pistol);
	eng.add(enemies);
	eng.add(p);
	eng.run();
	return 0;
}