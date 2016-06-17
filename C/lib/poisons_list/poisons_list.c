/* poison.c */

#include <stdio.h>
#include <stdlib.h>
#include "../poison/poison.h"
#include "poisons_list.h"

void poisons_list_init(PoisonsList *pl, int size, int screen_x, int screen_y)
{
    int i;

    poison_init(screen_x, screen_y);

    if (size<=0) {
        pl->poisons = NULL;
        pl->active = NULL;
        pl->size = 0;
        return;
    }

    pl->poisons = (Poison*)malloc(sizeof(Poison)*size);
    pl->active = (int*)malloc(sizeof(int)*size);
    for (i=0; i<size; i++) {
        pl->active[i] = 0;
    }
    pl->size = size;
}

void poisons_list_dump(PoisonsList *pl)
{
    int i;
    for (i=0; i<pl->size; i++) {
        if (pl->active[i]) {
            printf("POISON # %d\n", i);
            poison_dump(&(pl->poisons[i]));
            putchar('\n');
        }
    }
}

void poisons_list_destroy(PoisonsList *pl)
{
    free(pl->poisons);
    pl->poisons = NULL;
    free(pl->active);
    pl->active = NULL;
    pl->size = 0;
}

void poisons_list_oldify(PoisonsList *pl)
{
    int i;
    for (i=0; i<pl->size; i++) {
        if (pl->active[i]) {
            poison_oldify(&(pl->poisons[i]));
            if (poison_is_dead(&(pl->poisons[i]))) {
                pl->active[i] = 0;
            }
        }
    }
}

int poisons_list_find_free_index(PoisonsList *pl)
{
    int i = 0;

    while (pl->active[i]!=0 && i<pl->size) {
        i++;
    }

    if (i<pl->size) return i;

    return -1;
}

int poisons_list_add(PoisonsList *pl, Poison *p)
{
    int i = poisons_list_find_free_index(pl);
    if (i==-1) return -1;

    poison_copy(&(pl->poisons[i]), p);
    pl->active[i] = 1;
    return 0;
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
