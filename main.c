#include <stdio.h>
#include "compteur.h"
#include "serveur.h"

int main() {
    Compteur compteur;
    init_compteur(&compteur, "12345678", "9876");

    int choix;
    char token[32];

    while (1) {
        printf("\n1. Buy");
        printf("\n2. Enter token");
        printf("\n3. Consume");
        printf("\n4. Counter state");
        printf("\n0. Quit\n");
        printf("Choice : ");
        scanf("%d", &choix);

        if (choix == 1){
            int kwh;
            printf("kwh to buy : ");
            scanf("%d", &kwh);
            generer_token(compteur.id, compteur.cle, kwh, token);
            printf("🔢 Token : %s\n", token);
        }
        else if (choix == 2){
            printf("Enter the token : ");
            scanf("%s", token);
            entrer_token(&compteur, token);
        }
        else if (choix == 3){
            int kwh;
            printf("kwh to consome : ");
            scanf("%d", &kwh);
            consommer(&compteur, kwh);
        }
        else if (choix == 4){
            afficher_etat(&compteur);
        }
        else if (choix == 0){
            break;
        }
    }
    return 0;
}