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
    int *active;
    int size;
} PoisonsList;

void poisons_list_init(PoisonsList *pl, int size, int screen_x, int screen_y);
void poisons_list_dump(PoisonsList *pl);
void poisons_list_destroy(PoisonsList *pl);

/*
void poison_print(Poison *p);
int poison_num_free_slot(Poison *p, int size);
int poison_can_create(Poison *p, int size);
void poison_oldfy(Poison *p, int size);
*/

#endif
