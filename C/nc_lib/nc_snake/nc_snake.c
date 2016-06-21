#include <ncurses.h>
#include "../../lib/snake/snake.h"
#include "../../lib/position/position.h"
#include "nc_snake.h"

void nc_snake_print(Snake *snake)
{
    int i;

    Position* current = snake_get_head_pos(snake);
    mvaddch(current->y, current->x, '@');

    for (i=1; i<snake_get_len(snake); i++) {
        current = snake_get_cell(snake, i);
        mvaddch(current->y, current->x, 'm');
    }
}

void nc_snake_unprint(Snake *snake)
{
    int i;
    Position* current;

    for (i=0; i<snake_get_len(snake); i++) {
        current = snake_get_cell(snake, i);
        mvaddch(current->y, current->x, ' ');
    }
}
