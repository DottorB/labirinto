#include "header.h"
#include <stdio.h>
#include <stdlib.h>


//tramite questa funzione ci saranno messaggi che spiegano in generale il percorso del robot, ci sarà la
//generazione del labirinto solo con le pareti esterne e la scelta di 1 dei 3 labirinti a disposizione
void scegli_labirinto(char stampa_matrice[16][16]) {
    int opzione = 0;
    //istruzioni per il movimento del robot e selezione del labirinto
    printf("Benvenuto nel labirinto del robot! \n");
    printf("IMPORTANTE \nle X sono pareti interne ed esterne ed il robot non ci puo' passare \n");
    printf("I cerchi (O) rappresentano la strada percorribile dal robot \n");
    printf("al suo passaggio il robot lasciera' dei puntini (.) e non potra' tornare indietro \n");
    printf("selezionare un numero da 1 a 3 per scegliere il labirinto \n");

    scanf("%d", &opzione);
    //tramite due cicli for annidati e una serie di if si genera il labirinto con pareti e uscite
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (i == 0 || i == 15 || j == 0 || j == 15) {
                stampa_matrice[i][j] = 'X';
            } else {
                stampa_matrice[i][j] = 'O';
            }

            if (i >= 11 && i <= 13 && j == 0) {
                stampa_matrice[i][j] = 'E';
            }
        }
    }

    //con switch si permette la scelta di un labirinto
    switch (opzione) {
        case 1: stampa_labirinto_1(stampa_matrice);
            break;
        case 2: stampa_labirinto_2(stampa_matrice);
            break;
        case 3: stampa_labirinto_3(stampa_matrice);

        default: printf("comando non disponibile \n");
    }
}

//primo labirinto, inizializzo tramite due cicli for annidati e una serie di if le posizioni dei muri interni
void stampa_labirinto_1(char stampa_matrice[16][16]) {
    for (int i = 0; i < 16; i++) {
        printf("\n");

        for (int j = 0; j < 16; j++) {
            if (i >= 2 && i <= 9 && j == 3) {
                stampa_matrice[i][j] = 'X';
            }


            if (i == 3 && j >= 7 && j <= 15) {
                stampa_matrice[i][j] = 'X';
            }


            if (i >= 8 && i <= 15 && j == 7) {
                stampa_matrice[i][j] = 'X';
            }


            if (i == 10 && j >= 11 && j <= 13) {
                stampa_matrice[i][j] = 'X';
            }
            //tramite printf stampo il labirinto completo visibile all'utente
            printf("[%c]", stampa_matrice[i][j]);
        }
    }

    printf("\n");

    int passo = 0;

    //richiamo della funzione di uscita, cioè di tutto il percorso del robot fino a 'E'
    uscita_labirinto(passo, stampa_matrice);
}

//secondo labirinto, inizializzo tramite due cicli for annidati e una serie di if le posizioni dei muri interni
void stampa_labirinto_2(char stampa_matrice[16][16]) {
    for (int i = 0; i < 16; i++) {
        printf("\n");

        for (int j = 0; j < 16; j++) {
            if ((i == 10 || i == 14) && (j >= 1 && j <= 15)) {
                stampa_matrice[i][j] = 'X';
            }
            if (i >= 11 && i <= 12 && j == 12)
                stampa_matrice[i][j] = 'X';

            if (i >= 12 && i <= 13 && j == 9)
                stampa_matrice[i][j] = 'X';
            if (i >= 11 && i <= 12 && j >= 5 && j <= 6)
                stampa_matrice[i][j] = 'X';
            if (i >= 12 && i <= 13 && j == 2)
                stampa_matrice[i][j] = 'X';
            //tramite printf stampo il labirinto completo visibile all'utente
            printf("[%c]", stampa_matrice[i][j]);
        }
    }

    printf("\n");

    int passo = 0;
    //richiamo della funzione di uscita, cioè di tutto il percorso del robot fino a 'E'
    uscita_labirinto(passo, stampa_matrice);
}

//terzo labirinto, inizializzo tramite due cicli for annidati e una serie di if le posizioni dei muri interni
void stampa_labirinto_3(char stampa_matrice[16][16]) {
    for (int i = 0; i < 16; i++) {
        printf("\n");
        for (int j = 0; j < 16; j++) {
            if (i >= 2 && i <= 10 && j == 13)
                stampa_matrice[i][j] = 'X';
            if (i == 9 && j >= 3 && j <= 5)
                stampa_matrice[i][j] = 'X';
            if (i >= 11 && i <= 15 && j == 8)
                stampa_matrice[i][j] = 'X';
            if (i >= 1 && i <= 3 && j == 6)
                stampa_matrice[i][j] = 'X';
            //tramite printf stampo il labirinto completo visibile all'utente
            printf("[%c] ", stampa_matrice[i][j]);
        }
    }
    printf("\n");

    int passo = 0;
    //richiamo della funzione di uscita, cioè di tutto il percorso del robot fino a 'E'
    uscita_labirinto(passo, stampa_matrice);
}

//funzione che stampa tutto il percorso del robot fino all'uscita con le condizioni richieste dalla consegna
//per la scelta del percorso casuale
int uscita_labirinto(int passo, char stampa_matrice[16][16]) {
    int robot_x = 0, robot_y = 0;

    int scelta = 0;
    //tramite while impongo al programma di non andare avanti fino a quando non verrà scelta
    //una posizione valida per il robot

    while (scelta == 0) {
        //inserisci la coordinata che equivale al numero della colonna dove posizionare il robot
        printf("inserisci la colonna \n");
        scanf("%d", &robot_x);
        //inserisci la coordinata che equivale al numero della colonna dove posizionare il robot
        printf("inserisci la riga \n");
        scanf("%d", &robot_y);
        //se la posizione è valida si va avanti altrimenti bisogna rimetterla
        if (robot_x > 0 && robot_x < 16 && robot_y > 0 && robot_y < 16 && stampa_matrice[robot_y][robot_x] == 'O') {
            stampa_matrice[robot_y][robot_x] = 'R';

            scelta = 1;
        } else {
            printf("impossibile posizionare il robot in quella posizione \n");
        }
    }
    //variabile che permetterà il riconoscimento del passo precedente per non tornare indietro
    int passo_precedente = -1;

    int risultato_p;
    //con il do sceglie tutte le opzioni per ogni singolo passo permettendogli di stampare
    //il labirinto e ogni passo fino a 'E'
    do {
        //rand permette di scegliere casualmente un numero da 1 a 100
        risultato_p = rand() % 100 + 1;

        //if permette di attivare la condizione del passo casuale per un risultato da 1 a 30 (il 30% dei casi)
        if (risultato_p >= 1 && risultato_p <= 30) {
            //inizializza un passo casuale tra i 4
            passo = rand() % 4;

            printf("%d\n", passo);

            //inizializzo le varie condizioni per cui è possibile posizionare il robot, evitando anche di tornare indietro
            //rispetto al suo ultimo passo, mettendo una R nella sua posizione corrente e un . per la sua posizione precedente
            if (passo == 0 && (robot_y + 1 < 16) && (
                    stampa_matrice[robot_y + 1][robot_x] == 'O' || stampa_matrice[robot_y + 1][robot_x] == '.' ||
                    stampa_matrice[robot_y + 1][robot_x] == 'E') && passo_precedente != 1) {
                stampa_matrice[robot_y][robot_x] = '.';
                robot_y++;
                stampa_matrice[robot_y][robot_x] = 'R';
                passo_precedente = 0;
                stampa_percorso(stampa_matrice);
            } else if (passo == 1 && (robot_y - 1 >= 0) && (
                           stampa_matrice[robot_y - 1][robot_x] == 'O' || stampa_matrice[robot_y - 1][robot_x] == '.' ||
                           stampa_matrice[robot_y - 1][robot_x] == 'E') && passo_precedente != 0) //su
            {
                stampa_matrice[robot_y][robot_x] = '.';
                robot_y--;
                stampa_matrice[robot_y][robot_x] = 'R';
                passo_precedente = 1;
                stampa_percorso(stampa_matrice);
            } else if (passo == 2 && (robot_x + 1 < 16) && (
                           stampa_matrice[robot_y][robot_x + 1] == 'O' || stampa_matrice[robot_y][robot_x + 1] == '.' ||
                           stampa_matrice[robot_y][robot_x + 1] == 'E') && passo_precedente != 3) //destra
            {
                stampa_matrice[robot_y][robot_x] = '.';
                robot_x++;
                stampa_matrice[robot_y][robot_x] = 'R';
                passo_precedente = 2;
                stampa_percorso(stampa_matrice);
            } else if (passo == 3 && (robot_x - 1 >= 0) && (
                           stampa_matrice[robot_y][robot_x - 1] == 'O' || stampa_matrice[robot_y][robot_x - 1] == '.' ||
                           stampa_matrice[robot_y][robot_x - 1] == 'E') && passo_precedente != 2) //sinistra
            {
                stampa_matrice[robot_y][robot_x] = '.';
                robot_x--;
                stampa_matrice[robot_y][robot_x] = 'R';
                passo_precedente = 3;
                stampa_percorso(stampa_matrice);
            }
            //tramite else if avvio la seconda condizione, quindi la generazione di numeri casuali da 31 a 100
            //il 70% dei casi
        } else if (risultato_p >= 31 && risultato_p <= 100) {
            int max_distanza = -1, miglior_distanza = -1;
            int distanze[4] = {0, 0, 0, 0};
            int temp_giu = robot_y + 1, temp_su = robot_y - 1, temp_destra = robot_x + 1, temp_sinistra = robot_x - 1;
            //tramite while faccio "vedere" al robot sla direzione più lunga aumentando 4 variabili di un array
            while (temp_giu < 16 && stampa_matrice[temp_giu][robot_x] != 'X') {
                distanze[0]++;
                temp_giu++;
            }

            while (temp_su >= 0 && stampa_matrice[temp_su][robot_x] != 'X') {
                distanze[1]++;
                temp_su--;
            }

            while (temp_destra < 16 && stampa_matrice[robot_y][temp_destra] != 'X') {
                distanze[2]++;
                temp_destra++;
            }
            while (temp_sinistra >= 0 && stampa_matrice[robot_y][temp_sinistra] != 'X') {
                distanze[3]++;
                temp_sinistra--;
            }
            int i = 0, contatore = 0;
            int direzioni_massime[4];
            //se una delle 4 direzioni è più grande delle altre sceglie quella

            for (i = 0; i < 4; i++) {
                if (distanze[i] > max_distanza && i != passo_precedente) {
                    max_distanza = distanze[i];

                    miglior_distanza = i;
                    //se ci soo due o più valori uguali e maggiori degli altri sceglie a caso quale dei valori più grandi predere
                } else if (distanze[i] == max_distanza && i != passo_precedente) {
                    direzioni_massime[contatore] = i;

                    contatore++;
                }
                printf("%d e %d \n", distanze[i], miglior_distanza);
            }
            if (contatore > 1) {
                int scelta_casuale;

                scelta_casuale = rand() % contatore;

                miglior_distanza = scelta_casuale;
            }


            if (miglior_distanza == 0 && (robot_y + 1 < 16) && (
                    stampa_matrice[robot_y + 1][robot_x] == 'O' || stampa_matrice[robot_y + 1][robot_x] == '.' ||
                    stampa_matrice[robot_y + 1][robot_x] == 'E') && passo_precedente != 1) {
                stampa_matrice[robot_y][robot_x] = '.';
                robot_y++;
                stampa_matrice[robot_y][robot_x] = 'R';
                passo_precedente = 0;
                stampa_percorso(stampa_matrice);
            } else if (miglior_distanza == 1 && (robot_y - 1 < 16) && (
                           stampa_matrice[robot_y - 1][robot_x] == 'O' || stampa_matrice[robot_y - 1][robot_x] == '.' ||
                           stampa_matrice[robot_y - 1][robot_x] == 'E') && passo_precedente != 0) {
                stampa_matrice[robot_y][robot_x] = '.';
                robot_y--;
                stampa_matrice[robot_y][robot_x] = 'R';
                passo_precedente = 1;
                stampa_percorso(stampa_matrice);
            } else if (miglior_distanza == 2 && (robot_x + 1 < 16) && (
                           stampa_matrice[robot_y][robot_x + 1] == 'O' || stampa_matrice[robot_y][robot_x + 1] == '.' ||
                           stampa_matrice[robot_y][robot_x + 1] == 'E') && passo_precedente != 3) {
                stampa_matrice[robot_y][robot_x] = '.';
                robot_x++;
                stampa_matrice[robot_y][robot_x] = 'R';
                passo_precedente = 2;
                stampa_percorso(stampa_matrice);
            } else if (miglior_distanza == 3 && (robot_x + 1 < 16) && (
                           stampa_matrice[robot_y][robot_x - 1] == 'O' || stampa_matrice[robot_y][robot_x - 1] == '.' ||
                           stampa_matrice[robot_y][robot_x - 1] == 'E') && passo_precedente != 2) {
                stampa_matrice[robot_y][robot_x] = '.';
                robot_x--;
                stampa_matrice[robot_y][robot_x] = 'R';
                passo_precedente = 3;
                stampa_percorso(stampa_matrice);
            }
            int movimento_effettuato = 0;
            //se il robot non è riuscito a muoversi perché il movimento non è valido vede quale alternativa può fare

            for (int tentativo = 0; tentativo < 4 && !movimento_effettuato; tentativo++) {
                int direzione_attuale = (miglior_distanza + tentativo) % 4;
                if (direzione_attuale == 0 && (robot_y + 1 < 16) && (
                        stampa_matrice[robot_y + 1][robot_x] == 'O' || stampa_matrice[robot_y + 1][robot_x] == '.' ||
                        stampa_matrice[robot_y + 1][robot_x] == 'E') && passo_precedente != 1) {
                    stampa_matrice[robot_y][robot_x] = '.';
                    robot_y++;
                    stampa_matrice[robot_y][robot_x] = 'R';
                    passo_precedente = 0;
                    movimento_effettuato = 1;
                } else if (direzione_attuale == 1 && (robot_y - 1 >= 0) && (
                               stampa_matrice[robot_y - 1][robot_x] == 'O' || stampa_matrice[robot_y - 1][robot_x] ==
                               '.' || stampa_matrice[robot_y - 1][robot_x] == 'E') && passo_precedente != 0) {
                    stampa_matrice[robot_y][robot_x] = '.';
                    robot_y--;
                    stampa_matrice[robot_y][robot_x] = 'R';
                    passo_precedente = 1;
                    movimento_effettuato = 1;
                } else if (direzione_attuale == 2 && (robot_x + 1 < 16) && (
                               stampa_matrice[robot_y][robot_x + 1] == 'O' || stampa_matrice[robot_y][robot_x + 1] ==
                               '.' || stampa_matrice[robot_y][robot_x + 1] == 'E') && passo_precedente != 3) {
                    stampa_matrice[robot_y][robot_x] = '.';
                    robot_x++;
                    stampa_matrice[robot_y][robot_x] = 'R';
                    passo_precedente = 2;
                    movimento_effettuato = 1;
                } else if (direzione_attuale == 3 && (robot_x - 1 >= 0) && (
                               stampa_matrice[robot_y][robot_x - 1] == 'O' || stampa_matrice[robot_y][robot_x - 1] ==
                               '.' || stampa_matrice[robot_y][robot_x - 1] == 'E') && passo_precedente != 2) {
                    stampa_matrice[robot_y][robot_x] = '.';
                    robot_x--;
                    stampa_matrice[robot_y][robot_x] = 'R';
                    passo_precedente = 3;
                    movimento_effettuato = 1;
                }
            }
        }
        //richiama la variabile di stampa, ad ogni passo verrà stampato il labirinto e il passo aggiornato
        stampa_percorso(stampa_matrice);
        //aggiornerà i passi fino all'uscita
    } while (!(
        (robot_y == 11 && robot_x == 0) ||
        (robot_y == 12 && robot_x == 0) ||
        (robot_y == 13 && robot_x == 0)
    ));


    printf("il robot e' uscito dal labirinto! \n");

    int continuo;
    //permette di continuare una che il robot ha finito di percorrere un labirinto
    printf("premere 1 se si vuole continuare premere 0 se si vuole terminare il programma \n");

    scanf("%d", &continuo);

    if (continuo == 1) {
        scegli_labirinto(stampa_matrice);
    } else {
        return 0;
    }
}

//stampa ogni volta il labirinto con il passo corrente e quelli precedenti
void stampa_percorso(char stampa_matrice[16][16]) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            printf("[%c] ", stampa_matrice[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
