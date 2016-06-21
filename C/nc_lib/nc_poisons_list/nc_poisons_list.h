#ifndef NC_POISONS_LIST_H
#define NC_POISONS_LIST_H

#include "../../lib/poisons_list/poisons_list.h"
#include "../../lib/poison/poison.h"
#include "../../lib/position/position.h"

typedef struct {
    PoisonsList pl;
    Position *positions;
} NC_PoisonsList;

void nc_poisons_list_init(NC_PoisonsList *nc_pl, int size);
int nc_poisons_list_add(NC_PoisonsList *nc_pl, Poison *p, Position *pos);
void nc_poisons_list_print(NC_PoisonsList *nc_pl);

#endif
