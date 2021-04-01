#ifndef _object_h_
#define _object_h_

typedef enum
{
	NORTH, SOUTH, WEST, EAST
}Directions;

typedef struct
{
	char *description;
	int (*init)(void *self);
	void (*describe)(void *self);
	void (*destroy)(void *self);
	void *(*move)(void *self, Direction direction);
	int (*attack)(void *self, int damage);
}Object;

int objectInit(void *self);
void objectDestroy(void *self);
void objectDesribe(void *self);
void *objectMove(void *self, Direction direction);
int *objectAttack(void *self, int damage);
void *objectNew(size_t size, Object proto, char *description);

#define NEW(T, N) objectNew(sizeof(T), T##Proto, N)
#define _(N) proto.N

#endif
 
