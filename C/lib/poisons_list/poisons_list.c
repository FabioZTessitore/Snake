/* poison.c */

#include <stdio.h>
#include <stdlib.h>
#include "poison.h"
#include "poisons_list.h"

int poisons_list_find_free_index(PoisonsList *pl);

void poisons_list_init(PoisonsList *pl, int length)
{
  int i;

  poison_init();

  if (length<=0) {
    pl->poisons = NULL;
    pl->active = NULL;
    pl->length = 0;
    return;
  }

  /* alloca memoria per i Poison (inattivi) */
  pl->poisons = (Poison*)malloc(sizeof(Poison)*length);
  if (!pl->poisons) {
    fprintf(stderr, "Impossibile allocare memoria\n");
    exit(-1);
  }
  pl->active = (int*)malloc(sizeof(int)*length);
  if (!pl->active) {
    fprintf(stderr, "Impossibile allocare memoria\n");
    exit(-1);
  }
  for (i=0; i<length; i++) {
    pl->active[i] = 0;
  }
  pl->length = length;
}

void poisons_list_dump(PoisonsList *pl)
{
  int i;

  for (i = 0; i < pl->length; i++) {
    if (pl->active[i]) {
      printf("POISON # %d\n", i);
      poison_dump(&(pl->poisons[i]));
      putchar('\n');
    }
  }
}

void poisons_list_destroy(PoisonsList *pl)
{
  if (pl->poisons) {
    free(pl->poisons);
    pl->poisons = NULL;
  }
  if (pl->active) {
    free(pl->active);
    pl->active = NULL;
  }
  pl->length = 0;
}

void poisons_list_oldify(PoisonsList *pl)
{
  int i;

  for (i = 0; i < pl->length; i++) {
    if (pl->active[i]) {
      poison_oldify(&(pl->poisons[i]));
      if (poison_is_dead(&(pl->poisons[i]))) pl->active[i] = 0;
    }
  }
}

int poisons_list_find_free_index(PoisonsList *pl)
{
  int i = 0;

  while (pl->active[i] != 0 && i < pl->length) {
    i++;
  }

  if (i < pl->length) return i;

  return -1;
}

int poisons_list_add(PoisonsList *pl, Poison *p)
{
  int i = poisons_list_find_free_index(pl);

  if (i == -1) return -1;

  poison_copy(&(pl->poisons[i]), p);
  pl->active[i] = 1;

  return i;
}
