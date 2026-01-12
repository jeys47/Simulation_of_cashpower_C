#include "crypto.h"
#include <string.h>

void chiffrer(const char *message, const char *cle, char *token) {
    int len_msg = strlen(message);
    int len_cle = strlen(cle);

    for (int i=0; i < len_msg; i++){
        int m = message[i] - '0';
        int k = cle[i % len_cle] - '0';
        token[i] = ((m + k) % 10) + '0';
    }
    token[len_msg] = '\0';
}

void dechiffrer(const char *token, const char *cle, char *message){
    int len_tok = strlen(token);
    int len_cle = strlen(cle);

    for (int i=0; i < len_tok; i++){
        int t = token[i] - '0';
        int k = cle[i % len_cle] - '0';
        message[i] = ((t - k + 10) % 10) + '0';
    }
    message[len_tok] = '\0';
}