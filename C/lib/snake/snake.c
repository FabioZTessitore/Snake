/* snake.c */

#include <stdio.h>
#include <stdlib.h>
#include "position.h"
#include "snake.h"

void snake_set_cell(Snake *snake, int index, Position *pos);

void snake_init(Snake *snake, int len, Position *start, int direction)
{
  int i;

  if (len > SNAKE_MAX_LENGTH) {
    fprintf(stderr, "snake_init(): len > %d\n", SNAKE_MAX_LENGTH);
    exit(-1);
  } else if (len < 1) {
    fprintf(stderr, "snake_init(): len < 1\n");
    exit(-1);
  }

  snake->riemp = len;
  snake->direction = direction;

  snake_set_cell(snake, 0, start);
  for (i = 1; i < snake->riemp; i++) {
    snake_set_cell(snake, i, snake_get_cell(snake, i-1));
    switch (direction) {
      case LEFT:
        (snake->cell[i]).x += 1;
        break;
      case RIGHT:
        (snake->cell[i]).x -= 1;
        break;
      case UP:
        (snake->cell[i]).y += 1;
        break;
      case DOWN:
        (snake->cell[i]).y -= 1;
        break;
      default:
        fprintf(stderr, "snake_init(): direzione non valida\n");
        break;
      }
  }
}

int snake_get_len(Snake *snake)
{
  return snake->riemp;
}

int snake_get_direction(Snake *snake)
{
  return snake->direction;
}

void snake_set_direction(Snake *snake, int direction)
{
  snake->direction = direction;
}

Position* snake_get_cell(Snake *snake, int index)
{
  if (index >= 0 && index < snake->riemp) {
    return &(snake->cell[index]);
  }

  return NULL;
}

void snake_set_cell(Snake *snake, int index, Position *pos)
{
  position_copy(&(snake->cell[index]), pos);
}

void snake_dump(Snake *snake)
{
  int i;

  printf("Dimensione snake: %d/%d\n", snake_get_len(snake), SNAKE_MAX_LENGTH);
  printf("Direzione snake: %d (%d UP, %d LEFT, %d DOWN, %d RIGHT)\n", snake_get_direction(snake), UP, LEFT, DOWN, RIGHT);
  printf("Posizione della testa: ");
  position_dump(snake_get_head_pos(snake));
  putchar('\n');
  printf("Celle:\n");
  for (i = 0; i < snake_get_len(snake); i++) {
    position_dump(snake_get_cell(snake, i));
  }
  putchar('\n');
}

Position* snake_get_head_pos(Snake *snake)
{
  return snake_get_cell(snake, 0);
}

void snake_grow(Snake *snake)
{
  if (snake_get_len(snake) >= SNAKE_MAX_LENGTH)
    return;

  snake->riemp++;
  /* la posizione verra' impostata quando lo Snake si muove */
}

void snake_shrink(Snake *snake)
{
  if (snake_get_len(snake) <= 0)
    return;

  snake->riemp--;
}

void snake_update_position(Snake *snake)
{
  int dx, dy;
  int i;
  Position* head;
  Position new_head;

  switch(snake_get_direction(snake)) {
    case UP:
      dx = 0;
      dy = -1;
      break;
    case LEFT:
      dx = -1;
      dy = 0;
      break;
    case DOWN:
      dx = 0;
      dy = 1;
      break;
    case RIGHT:
      dx = 1;
      dy = 0;
      break;
    default:
      fprintf(stderr, "snake_update_position(): direzione non valida\n");
      break;
  }

  head = snake_get_head_pos(snake);
  position_copy(&new_head, head);
  position_move(&new_head, dx, dy);

  for (i = snake_get_len(snake)-2; i >= 0; i--) {
    snake_set_cell(snake, i+1, snake_get_cell(snake, i));
  }
  snake_set_cell(snake, 0, &new_head);
}

int snake_eat_itself(Snake *snake)
{
  Position *head = snake_get_head_pos(snake);
  int i;

  for (i = 1; i < snake_get_len(snake); i++) {
    if (position_equals(head, snake_get_cell(snake, i)))  return 1;
  }

  return 0;
}

int snake_pos_in(Snake *snake, Position *pos)
{
  int i;
  Position *cell;

  for (i = 0; i < snake_get_len(snake); i++) {
    cell = snake_get_cell(snake, i);
    if (position_equals(cell, pos)) return 1;
  }

  return 0;
}
