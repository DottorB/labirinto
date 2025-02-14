/*Il progetto prevede la generazione di 3 labirinti diversi l'uno dall'altro. Un robot deve uscire dai labirinti e
 *l'utente può sceglierne la posizione. I movimenti sono casuali per il 30%, mentre nel 70% dei casi viene scelta
 *la strada più lunga. Una volta completato un labirinto si può scegliere di rimettere il robot in uno dei 3 labirinti
 *cambiandone anche la posizione*/
#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
    //servirà per la generazione di numeri casuali per il percorso del robot
    srand(time(NULL));
    //array che formerà labirinto formato da 16 righe e 16 colonne
    char stampa_matrice[16][16];

    scegli_labirinto(stampa_matrice);

    return 0;
}
