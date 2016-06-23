/* poison.h */

#ifndef POISON_H
#define POISON_H

/* Poison
 *
 * Un veleno o un frutto
 */

#define VELENO 0
#define FRUTTO 1

typedef struct {
  int type;
  int character;
  int life;
} Poison;

void poison_init();
Poison poison_make();
void poison_dump(Poison *p);
void poison_oldify(Poison *p);
int poison_is_dead(Poison *p);
void poison_copy(Poison *dst, Poison *src);

#endif
