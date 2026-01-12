#ifndef COMPTEUR_H
#define COMPTEUR_H

#define MAX_TOKENS 50

typedef struct {
    char id[90];
    char cle[8];
    int credit_kwh;
    char tokens_utilises[MAX_TOKENS][32];
    int nb_tokens;
} Compteur;

void init_compteur(Compteur *c, const char *id, const char *cle);
int entrer_token(Compteur *c, const char *token);
void consommer(Compteur *c, int kwh);
void afficher_etat(const Compteur *c);

#endif