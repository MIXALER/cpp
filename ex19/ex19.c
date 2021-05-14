//
// Created by yuanh on 2021/3/2.
//
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ex19.h"


int monsterAttack(void *self, int damage)
{
    Monster *moster = self;

    printf("You attack %s!\n", moster->_(description));

    moster->hit_points -= damage;

    if(moster->hit_points > 0)
    {
        printf("It is still alive.\n");
        return 0;
    } else
    {
        printf("It is dead!\n");
        return 1;
    }
}

int monsterInit(void *self)
{
    Monster *monster = self;
    monster->hit_points = 10;
    return 1;
}

Object monsterProto = {
        .init = monsterInit.
                .attack = monsterAttack
};

void *roomMove(void *self, Direction direction)
{
    Room *room = self;
    Room *next = NULL;

    if(direction == NORTH && room->north)
    {
        printf("You go north, into:\n");
        next = room->north;
    } else if (direction == SOUTH && room->south)
    {
        printf("You go south, into:\n");
        next = room->south;
    } else if (direction == EAST && room->east)
    {
        printf("You go east, into:\n");
        next = room->east;
    } else if (direction == WEST && room->west)
    {
        printf("You go west, into:\n");
        next = room->west;
    } else
    {
        printf("You can't go that direction.");
        next = NULL;
    }

    if(next)
    {
        next->_(description)(next);
    }

    return next;
}

int roomAttack(void *self, int damage)
{
    Room *room = self;
    Monster *monster = room->badGuy;

    if(monster)
    {
        monster->_(attack)(monster, damage);
        return 1;
    } else
    {
        printf("You flail in the air at nothing. Idiot.\n");
        return 0;
    }
}

Object roomProto = {
        .move = roomMove,
        .attack = roomAttack
};

void *mapMove(void *self, Direction direction)
{
    Map *map = self;
    Room *location = map->location;
    Room *next = NULL;

    next = location->_(move)(location, direction);

    if(next)
    {
        map->location = next;
    }

    return next;
}

int mapAttack(void *self, int damage)
{
    Map *map = self;
    Room *location = map->location;

    return location->_(attack)(location, damage);
}

int mapInit(void *self)
{
    Map *map = self;

    Room *hall = NEW(Room, "The great Hall");
    Room *throne = NEW(Room, "The throne room");
    Room *arena = NEW(Room, "The arena, with the minotaur");
    Room *kitchen = NEW(Room, "Kitchen, you have the knife now");

    arena->badGuy = NEW(Monster, "The evil minotaur");

    hall->north = throne;

    throne->west = arena;

    throne->east = kitchen;

    throne->south = hall;

    arena->east = throne;

    kitchen->west = throne;

    map->start = hall;
    map->location = hall;

    return 1;
}

Object mapProto = {
        .init = mapInit,
        .move = mapMove,
        .attack = mapAttack
};

int processInput(Map *game)
{
    printf("\n> ");

    char ch = getchar();

    getchar();

    int damage = rand() % 4;

    switch (ch) {
        case -1:
            printf("Giving up? You suck.\n");
            return 0;
            break;

        case 'n':
            game->_(move)(game, NORTH);
            break;

        case 's':
            game->_(move)(game, SOUTH);
            break;

        case 'e':
            game->_(move)(game, EAST);
            break;

        case 'w':
            game->_(move)(game, WEST);
            break;

        case 'a':
            game->_(attack)(game, damage);
            break;

        case 'l':
            printf("You can go: \n");
            if (game->location->north) printf("NORTH\n");
            if (game->location->south) printf("SOUTH\n");
            if (game->location->east) printf("EAST\n");
            if (game->location->west) printf("WEST\n");
            break;

        default:
            printf("What?: %d\n", ch);

    }
    return 1;
}

int main()
{
    srand(time(NULL));

    Map *game = NEW(Map, "The Hall of the Minotaur.");

    printf("You enter the ");
    game->location->_(description)(game->location);

    while (processInput(game))
    {

    }
    return 0
}