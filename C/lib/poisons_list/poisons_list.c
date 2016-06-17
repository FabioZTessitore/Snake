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
            printf("POISON # %d\n", (i+1));
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


/*
void poison_init(Poison *p, int size)
{
  srand(time(NULL));

  int i;
  for (i=0; i<size; i++) {
    (*(p+i)).active = 0;
  }
}

int poison_num_free_slot(Poison *p, int size)
{
  int i;
  int counter = 0;

  for (i=0; i<size; i++) {
    if ((*(p+i)).active==0) {
      counter++;
    }
  }

  return counter;
}

int poison_can_create(Poison *p, int size)
{
  int i;

  for (i=0; i<size; i++) {
    if ((*(p+i)).active==0) {
      return i;
    }
  }

  return -1;
}



void poison_destroy(Poison *p)
{
  p->active = 0;
  mvaddch(p->position.y, p->position.x, ' ');
}

void poison_print(Poison *p)
{
  mvaddch(p->position.y, p->position.x, p->character);
}

void poison_oldfy(Poison *p, int size)
{
  int i;
  for (i=0; i<size; i++) {
    if ((*(p+i)).active) {
      poison_age(p+i);
    }
  }
}

void poison_age(Poison *p)
{
  p->life--;
  if (p->life<=0) poison_destroy(p);
}

*/
