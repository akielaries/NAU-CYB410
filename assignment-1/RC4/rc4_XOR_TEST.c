/*
    robin verton, dec 2015
    implementation of the RC4 algo
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS 255 // (2^8)-1, bitmask for a byte
#define BYTE_LIMIT 256

// Function prototypes
void trad_swap(unsigned char *a, unsigned char *b);
void swap_values(unsigned char *a, unsigned char *b);
int RC4(char *key, char *plaintext, unsigned char *ciphertext);
int PRGA(unsigned char *S, char *plaintext, unsigned char *ciphertext);
int KSA(char *key, unsigned char *S);

void trad_swap(unsigned char *a, unsigned char *b) {
    int swapped = *a;
    *a = *b;
    *b = swapped;
}

/*
void swap_values(unsigned char *a, unsigned char *b) {
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}
*/

int KSA(char *key, unsigned char *S) {

  int len = strlen(key);
  int j = 0;

  for (int i = 0; i < BYTE_LIMIT; i++) {
    S[i] = i;
  }

  for (int i = 0; i < BYTE_LIMIT; i++) {
    j = (j + S[i] + key[i % len]) % BYTE_LIMIT;

    //swap_values(&S[i], &S[j]);
    trad_swap(&S[i], &S[j]);
  }
  return 0;
}

int PRGA(unsigned char *S, char *plaintext, unsigned char *ciphertext) {

  int i = 0;
  int j = 0;

  for (size_t n = 0, len = strlen(plaintext); n < len; n++) {
    i = (i + 1) % BYTE_LIMIT;
    j = (j + S[i]) % BYTE_LIMIT;

    //swap_values(&S[i], &S[j]);
    trad_swap(&S[i], &S[j]);

    int rnd = S[(S[i] + S[j]) % BYTE_LIMIT];

    ciphertext[n] = rnd ^ plaintext[n];
  }
  return 0;
}

int RC4(char *key, char *plaintext, unsigned char *ciphertext) {

  unsigned char S[BYTE_LIMIT];
  KSA(key, S);

  PRGA(S, plaintext, ciphertext);

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <key> <plaintext>", argv[0]);
    return EXIT_FAILURE;
  }

  unsigned char *ciphertext =
      malloc(sizeof(int) * strlen(argv[2]));
  if (ciphertext == NULL) {
    fprintf(stderr, "[-] Failed to allocate memory");
    exit(EXIT_FAILURE);
  }

  RC4(argv[1], argv[2], ciphertext);

  for (size_t i = 0, len = strlen(argv[2]); i < len; i++) {
    printf("%02hhX", ciphertext[i]);
  }

  free(ciphertext);

  // return EXIT_SUCCESS;
  return 0;
}
