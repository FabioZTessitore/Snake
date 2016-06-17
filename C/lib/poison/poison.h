/* poison.h */

#ifndef POISON_H
#define POISON_H

/* Poison
 *
 * Un veleno o un frutto
 */

#include "../position/position.h"

typedef struct {
  int type;
  int character;
  int life;
  Position position;
} Poison;

void poison_init(int screen_x, int screen_y);
Poison poison_make();
void poison_dump(Poison *p);
void poison_oldify(Poison *p);

#endif
