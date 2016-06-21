#ifndef SNAKE_H
#define SNAKE_H

#include "../position/position.h"

#define SNAKE_MAX_LENGTH 100

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

typedef struct {
  Position cell[SNAKE_MAX_LENGTH];
  int riemp;
  int direction;
} Snake;

void snake_init(Snake *snake, int len, Position *start, int direction);
int snake_get_len(Snake *snake);
int snake_get_direction(Snake *snake);
void snake_set_direction(Snake *snake, int direction);
Position* snake_get_cell(Snake *snake, int index);
void snake_set_cell(Snake *snake, int index, Position *pos);
void snake_dump(Snake *snake);
Position* snake_get_head_pos(Snake *snake);
void snake_grow(Snake *snake);
void snake_update_position(Snake *snake);
void snake_shrink(Snake *snake);
int snake_eat_itself(Snake *snake);
int snake_pos_in(Snake *snake, Position *pos);


/*
void snake_print(Snake *snake);
void snake_unprint(Snake *snake);
*/

/*
int snake_wall_impact(Snake *snake, int screen_x, int screen_y);
*/

#endif
