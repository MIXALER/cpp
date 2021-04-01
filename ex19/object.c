#include<stdio.h>
#include"object.h"
#include<string.h>
#include<stdlib.h>
#include<assert.h>

void objectDestroy(void *self)
{
	Object *obj = self;
	if(obj)
	{
		if(obj->description)
			free(obj->description);
		free(obj);
	}
}

void objectDescripion(void *self)
{
	Object *obj = self;
	printf("%s.\n", obj->description);
}

void objectInit(void *self)
{
	return 1;
}

void objectMove(void *self, Direciton direction)
{
	printf("you cann't move to this direction\n");
	return NULL;
}

void objectAttack(void *self, int damage)
{
	printf("you cann't attack that.\n");
	return 0;
}

void *objectNew(size_t size, Object proto, char *description)
{
	if(!proto.init) proto.init = objectInit;
	if(!proto.describe) proto.describe = objectDescribe;
	if(!proto.destroy) proto.destroy = objectDestroy;
	if(!proto.attack) proto.attack = objectAttack;
	if(!proto.move) proto.move = objectMove;
	
	Object *el = calloc(1, size);
	*el = proto;

	el->description = strup(description);
	
	if(!el->init(el))
	{
		el->destroy(el);
		return NUll;
	}
	else
		return el;
}

	
