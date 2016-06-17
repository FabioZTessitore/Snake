#include <stdio.h>
#include "poisons_list.h"

int main()
{
    PoisonsList pl;

    poisons_list_init(&pl, 10, 24, 5);

    poisons_list_dump(&pl);

    poisons_list_destroy(&pl);

    return 0;
}
