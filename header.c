#include "header.h"
#include <stdio.h>
#include <stdlib.h>



void scegli_labirinto(char stampa_matrice[16][16]){

    int opzione = 0;

    printf("Benvenuto nel labirinto del robot! \n");
    printf("IMPORTANTE \nle X sono pareti interne ed esterne ed il robot non ci puo' passare \n");
    printf("I cerchi (O) rappresentano la strada percorribile dal robot \n");
    printf("al suo passaggio il robot lasciera' dei puntini (.) e non potra' tornare indietro \n");
    printf("selezionare un numero da 1 a 3 per scegliere il labirinto \n");

    scanf("%d", &opzione);

    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 16; j++) {
            if (i==0 || i==15 || j==0 || j==15) {

                stampa_matrice[i][j] = 'X';

            }
            else {
                stampa_matrice[i][j] = 'O';
            }

            if  (i>=11 && i<=13 && j==0) {

                    stampa_matrice[i][j] = 'E';
                }



        }
    }


    switch (opzione) {
        case 1: stampa_labirinto_1(stampa_matrice);
        break;
        case 2: stampa_labirinto_2(stampa_matrice);
        break;
        case 3: stampa_labirinto_3(stampa_matrice);

        default: printf("comando non disponibile \n");
    }

}


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

            printf("[%c]", stampa_matrice[i][j]);

        }
    }

    printf("\n");

    int passo = 0, vedi_direzione = 0;

    uscita_labirinto(passo, stampa_matrice);
}

void stampa_labirinto_2(char stampa_matrice[16][16]) {
    for (int i = 0; i < 16; i++) {
        printf("\n");

        for (int j = 0; j < 16; j++) {
            if ((i == 10 || i == 14) && (j >= 1 && j <= 15)) {
                stampa_matrice[i][j] = 'X';
            }
            if (i>=11 && i<=12 && j==12)
                stampa_matrice[i][j] = 'X';

            if (i>=12 && i<=13 && j==9)
                stampa_matrice[i][j] = 'X';
            if (i>=11 && i<=12 && j>=5 && j<=6)
                stampa_matrice[i][j] = 'X';
            if (i>=12 && i<=13 && j==2)
                stampa_matrice[i][j] = 'X';
            printf("[%c]", stampa_matrice[i][j]);

        }
    }

    printf("\n");

    int passo = 0;

    uscita_labirinto(passo, stampa_matrice);
}

void stampa_labirinto_3(char stampa_matrice[16][16]) {

    for (int i = 0; i < 16; i++) {
        printf("\n");
        for (int j = 0; j < 16; j++) {
            if (i>=2 && i<=10 && j==13)
                stampa_matrice[i][j] = 'X';
            if (i==9 && j>=3 && j<=5)
                stampa_matrice[i][j] = 'X';
            if (i>=11 && i<=15 && j==8)
                stampa_matrice[i][j] = 'X';
            if (i>=1 && i<=3 && j==6)
                stampa_matrice[i][j] = 'X';

            printf("[%c] ", stampa_matrice[i][j]);
            }
        }
    printf("\n");

    int passo = 0;

    uscita_labirinto(passo,stampa_matrice);
}


int uscita_labirinto(int passo, char stampa_matrice[16][16]) {
    int robot_x = 0, robot_y = 0;

    int scelta = 0;

    while (scelta == 0) {
        printf("inserisci la colonna \n");
        scanf("%d", &robot_x);

        printf("inserisci la riga \n");
        scanf("%d", &robot_y);

        if (robot_x > 0 && robot_x < 16 && robot_y > 0 && robot_y < 16 && stampa_matrice[robot_y][robot_x] == 'O') {
            stampa_matrice[robot_y][robot_x] = 'R';

            scelta = 1;
        } else {
            printf("impossibile posizionare il robot in quella posizione \n");
        }
    }

    int passo_precedente = -1;

    int risultato_p;
    int finito = 0;

    do {
        risultato_p = rand() % 100 + 1;


        if (risultato_p >= 1 && risultato_p <= 30) {
            passo = rand() % 4;

            printf("%d\n", passo);


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
        } else if (risultato_p >= 31 && risultato_p <= 100) {
            int max_distanza = -1, miglior_distanza = -1;
            int distanze[4] = {0, 0, 0, 0};
            int temp_giu = robot_y + 1, temp_su = robot_y - 1, temp_destra = robot_x + 1, temp_sinistra = robot_x - 1;

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

            for (i = 0; i < 4; i++) {
                if (distanze[i] > max_distanza && i != passo_precedente) {
                    max_distanza = distanze[i];

                    miglior_distanza = i;
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
        stampa_percorso(stampa_matrice);
    } while (!(
        (robot_y == 11 && robot_x == 0) ||
        (robot_y == 12 && robot_x == 0) ||
        (robot_y == 13 && robot_x == 0)
    ));


    printf("il robot e' uscito dal labirinto! \n");

    int continuo;

    printf("premere 1 se si vuole continuare premere 0 se si vuole terminare il programma \n");
    scanf("%d", &continuo);

    if (continuo == 1) {
       scegli_labirinto(stampa_matrice);

  }
    else if (continuo == 0) {

        return 0;
    }
}


void stampa_percorso(char stampa_matrice[16][16]) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            printf("[%c] ", stampa_matrice[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
