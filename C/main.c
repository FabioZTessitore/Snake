#include <ncurses.h>
#include <time.h>
#include "./lib/random/random.h"
#include "./lib/snake/snake.h"
#include "./lib/poison/poison.h"
#include "./lib/position/position.h"
#include "./nc_lib/nc_snake/nc_snake.h"
#include "./nc_lib/nc_poisons_list/nc_poisons_list.h"

void init();
void print_walls(int screen_x, int screen_y);
int is_time_to_add_a_poison();

void snake_eat_poison(Snake *snake, NC_PoisonsList *nc_pl);

int main()
{
    clock_t start, end;
    int elapsed;

    int end_game = 0;
    int ch = 0;

    Snake snake;
    int snake_len = 5;
    Position snake_start = position_make(20, 20);
    int direction = LEFT;

    Poison p;
    Position pos;
    NC_PoisonsList nc_pl;
    int num_poison = 10;

    int screen_x, screen_y;

    random_init();

    snake_init(&snake, snake_len, &snake_start, direction);
    nc_poisons_list_init(&nc_pl, num_poison);

    init();

    getmaxyx(stdscr, screen_y, screen_x);

    print_walls(screen_x, screen_y);

    while(!end_game) {
        start = clock();

        ch = getch();
        switch(ch) {
            case 'q':
                end_game = 1;
                break;
            case 'h':
                snake_set_direction(&snake, LEFT);
                break;
            case 'j':
                snake_set_direction(&snake, DOWN);
                break;
            case 'k':
                snake_set_direction(&snake, UP);
                break;
            case 'l':
                snake_set_direction(&snake, RIGHT);
                break;
        }

        nc_snake_unprint(&snake);
        snake_update_position(&snake);

        if (is_time_to_add_a_poison()) {
            p = poison_make();
            pos = position_make(
                random_between(1, screen_x-1),
                random_between(1, screen_y-1)
            );
            nc_poisons_list_add(&nc_pl, &p, &pos);
        }
        nc_poisons_list_print(&nc_pl);

        snake_eat_poison(&snake, &nc_pl);

        if (
            snake_eat_itself(&snake) ||
            nc_snake_wall_impact(&snake, screen_x, screen_y) ||
            snake_get_len(&snake)<1
        ) {
            end_game = 1;
        }

        poisons_list_oldify(&(nc_pl.pl));

        nc_snake_print(&snake);
        refresh();

        end = clock();
        elapsed = (double)(end-start)/CLOCKS_PER_SEC * 1000;
        napms(200-elapsed);
    }

    endwin();
    return 0;
}

void init()
{
    initscr();
    curs_set(0);
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
}

void print_walls(int screen_x, int screen_y)
{
    int i;

    /* top wall */
    for (i=0; i<screen_x; i++) mvaddch(0, i, '#');
    /* bottom wall */
    for (i=0; i<screen_x; i++) mvaddch(screen_y-1, i, '#');
    /* left wall */
    for (i=0; i<screen_y; i++) mvaddch(i, 0, '#');
    /* right wall */
    for (i=0; i<screen_y; i++) mvaddch(i, screen_x-1, '#');
}

int is_time_to_add_a_poison()
{
    return (random_between(0, 100) < 5);
}

void snake_eat_poison(Snake *snake, NC_PoisonsList *nc_pl)
{
    Position* head = snake_get_head_pos(snake);
    Position *pos;
    int i;
    int size = nc_pl->pl.list_size;

    for (i=0; i<size; i++) {
        if (nc_pl->pl.active[i]) {
            pos = &(nc_pl->positions[i]);
            if (position_equals(pos, head)) {
                if (nc_pl->pl.poisons[i].type==VELENO) {
                    snake_shrink(snake);
                } else {
                    snake_grow(snake);
                }
                nc_pl->pl.active[i] = 0;
            }
        }
    }
}
