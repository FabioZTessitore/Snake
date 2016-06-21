/* poison.c */

#include <stdio.h>
#include "../random/random.h"
#include "poison.h"

int poison_random_type();
int poison_random_life();
int poison_random_character(int type);

/* I caratteri utilizzati per veleni e frutti,
 * devono essere nello stesso numero
 */
char poisons_characters[2][3] = {
  {'x', 'w', '*'},  /* veleni */
  {'o', '&', 'O'}   /* frutti */
};
const int number_characters = sizeof(poisons_characters[0])/sizeof(char);

const int min_life = 20;
const int max_life = 100;

void poison_init()
{
    random_init();
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
    return random_between(min_life, max_life);
}

int poison_random_character(int type)
{
    int index = random_between(0, number_characters);
    return poisons_characters[type][index];
}

Poison poison_make()
{
    Poison p;

    p.type = poison_random_type();
    p.character = poison_random_character(p.type);
    p.life = poison_random_life();

    return p;
}

void poison_dump(Poison *p)
{
  printf("type: %d\n", p->type);
  printf("char: %c\n", p->character);
  printf("life: %d\n", p->life);
}

void poison_oldify(Poison *p)
{
    p->life--;
}

int poison_is_dead(Poison *p)
{
    return p->life <= 0;
}

void poison_copy(Poison *dst, Poison *src)
{
    dst->type = src->type;
    dst->character = src->character;
    dst->life = src->life;
}
