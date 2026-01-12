#ifndef CRYPTO_H
#define CRYPTO_H

void chiffrer(const char *message, const char *cle, char *token);
void dechiffrer(const char *token, const char *cle, char *message);

#endif