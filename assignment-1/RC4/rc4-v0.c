/*
 * C implementation of RC4 Stream Cipher Algorithm. 
 * Pass in a key + text string = HASH
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BITS 256   // 2^8

void swap(unsigned char *a, unsigned char *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int KSA(char *key, unsigned char *S) {

    int len = strlen(key);
    int j = 0;

    for(int i = 0; i < BITS; i++)
        S[i] = i;

    for(int i = 0; i < BITS; i++) {
        j = (j + S[i] + key[i % len]) % BITS;

        swap(&S[i], &S[j]);
    }

    return 0;
}

int PRGA(unsigned char *S, char *plaintext, unsigned char *ciphertext) {

    int i = 0;
    int j = 0;

    for(size_t n = 0, len = strlen(plaintext); n < len; n++) {
        i = (i + 1) % BITS;
        j = (j + S[i]) % BITS;

        swap(&S[i], &S[j]);
        int rnd = S[(S[i] + S[j]) % BITS];

        ciphertext[n] = rnd ^ plaintext[n];

    }

    return 0;
}

int RC4(char *key, char *plaintext, unsigned char *ciphertext) {

    unsigned char S[BITS];
    KSA(key, S);

    PRGA(S, plaintext, ciphertext);

    return 0;
}

int main(int argc, char *argv[]) {

    if(argc < 3) {
        printf("Usage: %s <key> <plaintext>", argv[0]);
        return -1;
    }

    unsigned char *ciphertext = malloc(sizeof(int) * strlen(argv[2]));

    RC4(argv[1], argv[2], ciphertext);

    for(size_t i = 0, len = strlen(argv[2]); i < len; i++)
        printf("%02hhX", ciphertext[i]);

    return 0;
}


