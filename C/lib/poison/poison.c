/* poison.c */

#include <stdio.h>
#include "../position/position.h"
#include "../random/random.h"
#include "poison.h"

int poison_random_type();
int poison_random_life();
int poison_random_character(int type);
Position poison_random_position();

/* I caratteri utilizzati per veleni e frutti,
 * devono essere nello stesso numero
 */
char poisons_characters[2][3] = {
  {'x', 'w', '*'},  /* veleni */
  {'o', '&', 'O'}   /* frutti */
};
const int number_characters = sizeof(poisons_characters[0])/sizeof(char);

/* dimensione dello schermo */
static int screen_x_size = 0;
static int screen_y_size = 0;

void poison_init(screen_x, screen_y)
{
    random_init();
    screen_x_size = screen_x;
    screen_y_size = screen_y;
}

int poison_random_type()
{
    /* type 0: veleno
       type 1: frutto
    */
  return random_between(0, 2);
}

int poison_random_life()
{
    return random_between(20, 100);
}

int poison_random_character(int type)
{
    int index = random_between(0, number_characters);
    return poisons_characters[type][index];
}

Position poison_random_position(int screen_x, int screen_y)
{
    return position_make(
        random_between(0, screen_x),
        random_between(0, screen_y)
    );
}

Poison poison_make()
{
    Poison p;

    p.type = poison_random_type();
    p.character = poison_random_character(p.type);
    p.life = poison_random_life();
    p.position = poison_random_position(screen_x_size, screen_y_size);

    return p;
}

void poison_dump(Poison *p)
{
  printf("type: %d\n", p->type);
  printf("char: %c\n", p->character);
  printf("life: %d\n", p->life);
  printf("pos: "); position_dump(&p->position); putchar('\n');
}

void poison_oldify(Poison *p)
{
    p->life--;
}
