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

int nc_snake_wall_impact(Snake *snake, int screen_x, int screen_y)
{
    Position* head = snake_get_head_pos(snake);

    if (head->x<=0 || head->x>=screen_x-1 || head->y<=0 || head->y>=screen_y-1)
        return 1;

    return 0;
}
