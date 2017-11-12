#include <stdio.h>
#include "poison.h"

int main()
{
    int i;
    Poison p;

    poison_init();

    for (i=0; i<3; i++) {
        printf("*** POISON ***\n");
        p = poison_make();
        poison_dump(&p);
        putchar('\n');
    }

    return 0;
}
