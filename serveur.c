#include "serveur.h"
#include "crypto.h"
#include <stdio.h>

void generer_token(const char *id_compteur, const char *cle, int kwh, char *token){
    char message[32];
    sprintf(message, "%s%d", id_compteur, kwh);
    chiffrer(message, cle, token);
}