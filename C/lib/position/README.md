# Il modulo `Position`

Il modulo `Position` definisce una posizione sulla griglia di gioco.

Una `Position` è costituita dalle coordinate `x` e `y`.

## Installazione

### Download
Assicurati di aver effettuato il download della repository:
```bash
$ git clone https://github.com/FabioZTessitore/Snake.git
```
### Compilazione
```bash
$ make test_position
```
## Esecuzione
```bash
$ ./test_position
```

# L'angolo dello svilupparore

## Modulo `Position`

Una `Position` è implementata come struct composta dai valori interi `x` e `y`.

```c
/* position.h */

typedef struct {
  int x;
  int y;
} Position;
```

Le funzionalità messe a disposizione sono:
- `position_make` (crea una Position)
- `position_print` (stampa la Position per debug)
- `position_equals` (confronta due Position)
