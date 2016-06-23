#ifndef NC_SNAKE_H
#define NC_SNAKE_H

#include "../../lib/snake/snake.h"

void nc_snake_print(Snake *snake);
void nc_snake_unprint(Snake *snake);
int nc_snake_wall_impact(Snake *snake, int screen_x, int screen_y);

#endif
