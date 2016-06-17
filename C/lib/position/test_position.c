/* test_position.c */

#include <stdio.h>
#include "position.h"

int main()
{
    int x1 = 3;
    int x2 = 2;
    int y1 = 4;
    int y2 = 6;
    Position p1, p2, p3;

    printf("Crea una Position con coordinate (%d, %d)\n", x1, y1);
    p1 = position_make(x1, y1);
    printf("Crea una Position con coordinate (%d, %d)\n", x2, y2);
    p2 = position_make(x2, y2);
    printf("Crea un'altra Position con coordinate (%d, %d)\n", x1, y1);
    p3 = position_make(x1, y1);

    printf("Stampa la posizione p1(%d, %d)\n", x1, y1);
    position_print(&p1);
    putchar('\n');

    printf("Le posizioni p1");
    position_print(&p1);
    printf(" e p2");
    position_print(&p2);
    printf(" sono uguali? ");
    printf( position_equals(&p1, &p2) ? "SI" : "NO");
    putchar('\n');

    printf("Le posizioni p1");
    position_print(&p1);
    printf(" e p3");
    position_print(&p3);
    printf(" sono uguali? ");
    printf( position_equals(&p1, &p3) ? "SI" : "NO");
    putchar('\n');

    return 0;
}
