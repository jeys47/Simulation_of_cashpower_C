#include "compteur.h"
#include "crypto.h"
#include <stdio.h>
#include <string.h>

void init_compteur(Compteur *c, const char *id, const char *cle){
    strcpy(c->id, id);
    strcpy(c->cle, cle);
    c->credit_kwh = 0;
    c->nb_tokens = 0;
}

static int token_deja_utilise(const Compteur *c, const char *token){
    for (int i = 0; i < c->nb_tokens; i++){
        if (strcmp(c->tokens_utilises[i], token) == 0)
        return 1;
    }
    return 0;
}

int entrer_token(Compteur *c, const char *token){
    if (token_deja_utilise(c, token)) {
        printf("❌ Token already used\n");
        return 0;
    }

    char message[32];
    dechiffrer(token, c->cle, message);

    if (strncmp(message, c->id, strlen(c->id)) != 0){
        printf("❌ Invalid token for this counter\n");
        return 0;
    }

    int kwh = atoi(message + strlen(c->id));
    c->credit_kwh += kwh;

    strcpy(c->tokens_utilises[c->nb_tokens++], token);

    printf("✅ Recharged : +%d kwh\n", kwh);
    return 1;
}

void consommer(Compteur *c, int kwh){
    if (c->credit_kwh >= kwh){
        c->credit_kwh -= kwh;
        printf("💡 Consommation : %d kwh\n", kwh);
    } else {
        printf("❌ Insufficent credit\n");
    }
}

void afficher_etat(const Compteur *c){
    printf("🎛️ Counter %s | Credit : %d kwh\n", c->id, c->credit_kwh);
}