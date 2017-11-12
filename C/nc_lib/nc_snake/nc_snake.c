/* nc_snake.c */

#include <ncurses.h>
#include "position.h"
#include "snake.h"
#include "nc_snake.h"

void nc_snake_print(Snake *snake, int flagUnPrint)
{
  int i;
  int headChar = '@';
  int bodyChar = 'm';

  if (flagUnPrint) {
    headChar = bodyChar = ' ';
  }

  Position* current = snake_get_head_pos(snake);
  mvaddch(current->y, current->x, headChar);

  for (i = 1; i < snake_get_len(snake); i++) {
    current = snake_get_cell(snake, i);
    mvaddch(current->y, current->x, bodyChar);
  }
}

int nc_snake_wall_impact(Snake *snake, int screen_x, int screen_y)
{
  Position* head = snake_get_head_pos(snake);

  if (head->x <= 0 || head->x >= screen_x-1 || head->y <= 0 || head->y >= screen_y-1)
    return 1;

  return 0;
}
