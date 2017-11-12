# Il modulo `Random`

Il modulo `Random` si occupa della generazione di numeri pseudocasuali
compresi in un intervallo.

## L'angolo dello sviluppatore
Prima di utilizzare l'unica funzione utile per la generazione di numeri pseudocasuali
messa a disposizione dal modulo `Random` (`random_between`)
bisogna inizializzare il generatore. Dell'operazione si occupa `random_init`.

```c
/* random.h */

/* random_init:
 *
 * inizializza il sistema di generazione
 * dei numeri pseudo-casuali
 */
void random_init();
```

Per generare numeri compresi nell'intervallo [min, max[ il
modulo mette a disposizione `random_between`:

```c
/* random.h */

/* random_between:
 *
 * genera e restituisce un numero
 * compreso tra min incluso e max escluso
 */
int random_between(int min, int max /* escluso */);
```
