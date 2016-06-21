/* test_snake.c */

#include <stdio.h>
#include "snake.h"
#include "../position/position.h"

int main()
{
    Snake snake;
    int len = 3;
    Position start = position_make(10, 5);  /* x = 10; y = 5 */
    int direction = LEFT;

    printf("Creazione di uno Snake\n");
    snake_init(&snake, len, &start, direction);
    snake_dump(&snake);

    printf("\n\nCrescita di snake\n");
    snake_grow(&snake);
    snake_update_position(&snake);
    snake_dump(&snake);

    printf("\nCambia direzione, va verso UP\n");
    snake_set_direction(&snake, UP);
    snake_update_position(&snake);
    snake_dump(&snake);


    /*
    Poison p;
    PoisonsList pl;
    int i;

    printf("Crea la lista di 5 Poison\n");
    poisons_list_init(&pl, 5);

    printf("Aggiunge i Poison alla lista\n");
    for (i=0; i<7; i++) {
        p = poison_make();

        if (poisons_list_add(&pl, &p)!=0) {
            printf("i: %d\tImpossibile aggiungere Poison\n", i);
        }
    }
    printf("Stampa la lista di Poison\n");
    poisons_list_dump(&pl);

    printf("Distrugge la lista e ristampa\n");
    poisons_list_destroy(&pl);
    poisons_list_dump(&pl);
    */

    return 0;
}
