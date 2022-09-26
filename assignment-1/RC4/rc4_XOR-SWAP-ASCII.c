/*
 * RC4 implementation with HEX->ASCII conversion
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
// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- 

void hext_to_ascii(char *str_ret,unsigned char hexText){ // some characters are not printable
    if (hexText < 32 || hexText >= 127) snprintf(str_ret,999,"%c", hexText+64);
    else snprintf(str_ret,999,"%c", hexText);
}

void str_hex_decode(char *dump_to, unsigned char *hex_encoded){
    size_t len = strlen((char *) hex_encoded);
    char *tempstring = malloc(sizeof(int) * len);
    for(size_t i = 0; i < len; i++){
        hext_to_ascii(tempstring,hex_encoded[i]);
        strcat(dump_to,tempstring);

    }
    free(tempstring);
}

void printAsciiTable(){
    int x;
    for (x = 0; x< 127; x++)
        if (x < 32)
            printf("non-printable: ^%-3c \\x%2.2x \\%3.3o %3d\n", x+64, x, x, x);
        else
            printf("    printable: \x20%-3c \\x%2.2x \\%3.3o %3d\n", x, x, x, x);
    fflush(stdout);
}
int main(int argc, char *argv[]) {
    printAsciiTable();
    if(argc < 3) {
        printf("Usage: %s <key> <plaintext>", argv[0]);
        return -1;
    }
    char *dump_to = malloc(sizeof(int) * strlen(argv[2]));

    unsigned char *ciphertext = malloc(sizeof(int) * strlen(argv[2]));
    RC4(argv[1], argv[2], ciphertext);
    for(size_t i = 0; i < strlen(argv[2]); i++)
        printf("\\x%02hhx", ciphertext[i]);
    printf("\n");

    strcpy(dump_to,"");
    str_hex_decode(dump_to, ciphertext);
    printf("encoded:%s\n",dump_to);
   
    char *decodedtext = (char *) ciphertext;
    RC4(argv[1], decodedtext, ciphertext);
    for(size_t i = 0; i < strlen(argv[2]); i++)
        printf("\\x%02hhx", ciphertext[i]);
    printf("\n");
    
    strcpy(dump_to,"");
    str_hex_decode(dump_to, ciphertext);
    printf("decoded:%s\n",dump_to);

    free(dump_to);
    free(ciphertext);
    return 0;
}
