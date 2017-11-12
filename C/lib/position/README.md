# Il modulo `Position`

Il modulo `Position` definisce una posizione sulla griglia di gioco.

Una `Position` è costituita dalle coordinate `x` e `y`.

## L'angolo dello svilupparore

Una `Position` è implementata come `struct` composta dai valori interi `x` e `y`.

```c
/* position.h */

typedef struct {
  int x;
  int y;
} Position;
```

Le funzionalità messe a disposizione sono:
- `position_make` (crea una Position)
- `position_dump` (stampa la Position, debug)
- `position_equals` (confronta due Position)
- `position_move` (modifica una posizione)
- `position_copy` (effettua una copia)
