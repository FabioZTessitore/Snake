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

void position_dump(Position *pos)
{
  printf("(%d, %d)", pos->x, pos->y);
}

void position_copy(Position *dst, Position *src)
{
  dst->x = src->x;
  dst->y = src->y;
}

void position_move(Position *pos, int dx, int dy)
{
  pos->x += dx;
  pos->y += dy;
}
