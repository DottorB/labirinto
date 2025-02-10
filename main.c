/*La stanza è pavimentata a tasselli quadrati (caselle) ed è dotata di pareti esterne e interne come in figura.
Il robot si muove sempre solo di una casella alla volta, scelta tra una delle quattro caselle vicine.
Il robot è in grado di “vedere”, cioè di stabilire, guardando in una delle quattro direzioni (avanti, indietro, sinistra, destra),
quante sono le caselle libere (in linea retta) fino alla parete. La legge con cui il robot si muove
è la seguente: nel 30% dei casi il robot si muove a caso in una delle quattro caselle vicine possibili (parete permettendo);
nel 70% dei casi il robot prima “vede” e individua la direzione (avanti, indietro, sinistra, destra) del movimento
(scegliendo quella cui corrisponde il percorso possibile più lungo; nel caso di più percorsi di minima lunghezza,
la direzione viene scelta a caso tra questi) e poi si muove (sempre di un solo passo) in quella direzione.
In ogni caso, il robot non deve mai fare un passo in una direzione e allo step successivo un passo nella direzione opposta. La
simulazione termina quando il robot “esce dalla porta” della stanza (in basso a sinistra nella figura).
L’algoritmo deve visualizzare il percorso del robot dopo ogni passo, mostrando la stanza e la posizione del robot.
Effettuare almeno 5 test, variando la posizione iniziale del robot. Effettuare anche 3 test cambiando ogni volta
la disposizione delle pareti nella stanza e cercando di trovare disposizioni critiche delle pareti
(per esempio, un corridoio lungo e stretto può portare a movimenti oscillatori del tipo destra- sinistra). */
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {

    srand(time(NULL));

    char stampa_matrice[16][16];

    scegli_labirinto(stampa_matrice);

    return 0;
}