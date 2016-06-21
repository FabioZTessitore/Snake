/* poisons_list.h */

#ifndef POISONS_LIST_H
#define POISONS_LIST_H

/* PoisonList
 *
 * Gestisce una lista di Poison
 */

#include "../poison/poison.h"

typedef struct {
    Poison *poisons;
    int list_size;
    int *active;
} PoisonsList;

void poisons_list_init(PoisonsList *pl, int size);
void poisons_list_dump(PoisonsList *pl);
void poisons_list_destroy(PoisonsList *pl);
void poisons_list_oldify(PoisonsList *pl);
int poisons_list_add(PoisonsList *pl, Poison *p);

#endif
