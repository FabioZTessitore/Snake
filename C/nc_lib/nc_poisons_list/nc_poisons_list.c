#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "nc_poisons_list.h"
#include "../../lib/poisons_list/poisons_list.h"

void nc_poisons_list_init(NC_PoisonsList *nc_pl, int size)
{
    poisons_list_init(&(nc_pl->pl), size);
    nc_pl->positions = (Position*)malloc(sizeof(Position)*size);
    if (!nc_pl->positions) {
        fprintf(stderr, "nc_poisons_list_init(): impossibile allocare memoria\n");
        exit(-1);
    }
}

int nc_poisons_list_add(NC_PoisonsList *nc_pl, Poison *p, Position *pos)
{
    int index = poisons_list_add(&(nc_pl->pl), p);

    if (index==-1) return -1;

    position_copy(&(nc_pl->positions[index]), pos);
    return index;
}

void nc_poisons_list_print(NC_PoisonsList *nc_pl)
{
    int i;
    int size = (nc_pl->pl).list_size;
    Position pos;
    Poison* p;

    for (i=0; i<size; i++) {
        p = &(nc_pl->pl.poisons[i]);
        position_copy(&pos, &(nc_pl->positions[i]));
        if (nc_pl->pl.active[i]) {
            mvaddch(pos.y, pos.x, p->character);
        } else {
            mvaddch(pos.y, pos.x, ' ');
        }
    }
}

/*
void poison_destroy(Poison *p)
{
  p->active = 0;
  mvaddch(p->position.y, p->position.x, ' ');
}

void poison_print(Poison *p)
{
  mvaddch(p->position.y, p->position.x, p->character);
}
*/
