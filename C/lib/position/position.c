/* position.c */

#include <stdio.h>
#include "position.h"

Position position_make(int x, int y)
{
    Position p;

    p.x = x;
    p.y = y;

    return p;
}

int position_equals(Position *pos1, Position *pos2)
{
  return (pos1->x==pos2->x && pos1->y==pos2->y);
}

void position_print(Position *pos)
{
  printf("(%d, %d)", pos->x, pos->y);
}
