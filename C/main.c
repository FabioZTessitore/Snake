#include <ncurses.h>
#include "./lib/snake/snake.h"
#include "./lib/poison/poison.h"
#include "./lib/position/position.h"
#include "./nc_lib/nc_snake/nc_snake.h"
#include "./nc_lib/nc_poisons_list/nc_poisons_list.h"

int main()
{
    int end = 0;
    int num_poison = 10;

    Snake snake;
    int snake_len = 5;
    Position start = position_make(20, 20);
    int direction = LEFT;
    int ch = 0;

    NC_PoisonsList nc_pl;
    nc_poisons_list_init(&nc_pl, num_poison);
    Poison p = poison_make();
    Position pos = position_make(10, 10);

    initscr();
    curs_set(0);
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);

    snake_init(&snake, snake_len, &start, direction);
    nc_poisons_list_add(&nc_pl, &p, &pos);

    while(!end) {
        nc_snake_print(&snake);
        nc_poisons_list_print(&nc_pl);

        ch = getch();
        switch(ch) {
            case 'h':
                end = 1;
                break;
        }
    }

    endwin();
    return 0;
}
