#ifndef _ex19_h_
#define _ex19_h_

#include "object.h"

struct Monster
{
	Object proto;
	int hit_points;
}

typedef struct Monster Monster;

int monsterAttack(void *self, int damage);

int monsterInit(void *self);

struct Room
{
	Object proto;
	
	Monster *badGuy;
	
	struct Room *north;
	struct Room *south;
	struct Room *east;
	struct Room *west;
};

typedef struct Room Room;

void *roomMove(void *self, Direction direction);
int roomAttack(void *self, int damage);
int roomInit(void *self);

struct Map
{
	Object proto;
	Room *start;
	Room *location;
};

typedef struct Map Map;

void *mapMove(void *self, Direction direction);
int mapAttack(void *self, int damage);
int mapInit(void *self);

#endif
