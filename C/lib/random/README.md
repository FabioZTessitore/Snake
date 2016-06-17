# Il modulo `random`

Il modulo `random` si occupa di inizializzare il generatore
di numeri pseudocasuali e della generazione di numeri compresi in un intervallo.

## L'angolo dello sviluppatore
Prima di utilizzare l'unica funzione messa a disposizione dal modulo
`random` bisogna inizializzare il generatore di numeri
pseudocasuali. Dell'operazione si occupa `random_init`.
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
int random_between(int min, int max);
```
