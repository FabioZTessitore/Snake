/* test_snake.c */

#include <stdio.h>
#include "position.h"
#include "snake.h"

int main()
{
  Snake snake;
  int len = 3;
  Position start = position_make(10, 5);  /* x = 10; y = 5 */
  int direction = LEFT;

  printf("Creazione di uno Snake di lunghezza %d\n", len);
  snake_init(&snake, len, &start, direction);
  snake_dump(&snake);

  printf("\n\nCrescita di snake\n");
  snake_grow(&snake);
  snake_update_position(&snake);
  snake_dump(&snake);

  printf("\nCambia direzione, va verso UP\n");
  snake_set_direction(&snake, UP);
  snake_update_position(&snake);
  snake_dump(&snake);

  return 0;
}
