#include <stdio.h>
#include "poison.h"
#include "poisons_list.h"

int main()
{
  Poison p;
  PoisonsList pl;
  int i;

  /* una lista di 5 Poison */
  printf("Crea la lista di 5 Poison\n");
  poisons_list_init(&pl, 5);

  printf("Aggiunge i Poison alla lista\n");
  for (i=0; i<7; i++) {
    p = poison_make();

    if (poisons_list_add(&pl, &p) < 0) {
      printf("i: %d\tImpossibile aggiungere Poison\n", i);
    } else {
      printf("i: %d\tAggiunto Poison\n", i);
    }
  }
  printf("Stampa la lista di Poison\n");
  poisons_list_dump(&pl);

  printf("Distrugge la lista e ristampa\n");
  poisons_list_destroy(&pl);
  poisons_list_dump(&pl);

  return 0;
}
