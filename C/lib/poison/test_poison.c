#include <stdio.h>
#include "poison.h"

int main()
{
    int i;
    Poison p;

    poison_init(24, 5);  /* schermo 24 colonne e 5 righe */

    for (i=0; i<3; i++) {
        printf("*** POISON ***\n");
        p = poison_make();
        poison_dump(&p);
        putchar('\n');
    }

    return 0;
}
