#include <stdio.h>
#include "../poison/poison.h"
#include "poisons_list.h"

int main()
{
    Poison p;
    PoisonsList pl;

    poisons_list_init(&pl, 10, 24, 5);

    p = poison_make();

    poisons_list_add(&pl, &p);
    poisons_list_dump(&pl);

    poisons_list_destroy(&pl);

    return 0;
}
