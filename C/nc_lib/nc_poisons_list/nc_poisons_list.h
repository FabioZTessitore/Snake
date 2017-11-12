/* nc_poisons_list.h */

/* una PoisonsList con capacita' di stampa */

#ifndef NC_POISONS_LIST_H
#define NC_POISONS_LIST_H

#include "position.h"
#include "poison.h"
#include "poisons_list.h"

typedef struct {
  PoisonsList pl;
  Position *positions;
} NC_PoisonsList;

void nc_poisons_list_init(NC_PoisonsList *nc_pl, int length);
int nc_poisons_list_add(NC_PoisonsList *nc_pl, Poison *p, Position *pos);
void nc_poisons_list_print(NC_PoisonsList *nc_pl);

#endif
