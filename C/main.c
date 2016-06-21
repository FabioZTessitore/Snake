#include <ncurses.h>
#include "./lib/snake/snake.h"
#include "./nc_lib/nc_snake/nc_snake.h"

int main()
{
    int end = 0;
    Snake snake;
    int snake_len = 5;
    Position start = position_make(20, 20);
    int direction = LEFT;
    int ch = 0;

    initscr();
    curs_set(0);
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);

    snake_init(&snake, snake_len, &start, direction);

    while(!end) {
        nc_snake_print(&snake);

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
