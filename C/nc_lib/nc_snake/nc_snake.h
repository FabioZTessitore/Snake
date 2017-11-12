/* nc_snake.h */

/* utility per la stampa di uno Snake */

#ifndef NC_SNAKE_H
#define NC_SNAKE_H

#include "snake.h"

void nc_snake_print(Snake *snake, int flagUnPrint);
int nc_snake_wall_impact(Snake *snake, int screen_x, int screen_y);

#endif
